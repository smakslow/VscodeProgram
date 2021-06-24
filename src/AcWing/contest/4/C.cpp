#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int d, u, v;
};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<Edge> edges(m);
        vector<vector<int>> adj1(n + 1), adj2(n + 1);
        vector<int> deg(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int d, u, v;
            scanf("%d%d%d", &d, &u, &v);
            edges[i].d = d, edges[i].u = u, edges[i].v = v;
            if (d)
            {
                adj1[u].emplace_back(v);
                deg[v]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (!deg[i])
                q.emplace(i);
        vector<int> order(n + 1);
        vector<int> topo;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.emplace_back(u);
            for (int v : adj1[u])
            {
                deg[v]--;
                if (!deg[v])
                    q.emplace(v);
            }
        }
        if (topo.size() != n)
        {
            printf("NO\n");
            continue;
        }
        for (int i = 0; i < n; ++i)
            order[topo[i]] = i;
        printf("YES\n");
        for (int i = 0; i < m; ++i)
        {
            if (edges[i].d || order[edges[i].u] < order[edges[i].v])
            {
                assert(order[edges[i].u] < order[edges[i].v]);
                printf("%d %d\n", edges[i].u, edges[i].v);
            }
            else
            {
                printf("%d %d\n", edges[i].v, edges[i].u);
            }
        }
    }
}
