#include <bits/stdc++.h>

using namespace std;

const int N = 6005;
int value[N], dp[N][2], father[N], n;
vector<int> tree[N];

void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = value[u];
    for (int i = 0; i < tree[u].size(); i++)
    {
        int son = tree[u][i];
        dfs(son);
        dp[u][0] += max(dp[son][1], dp[son][0]);
        dp[u][1] += dp[son][0];
    }
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> value[i];
            tree[i].clear();
            father[i] = -1;
        }
        while (1)
        {
            int a, b;
            cin >> a >> b;
            if (a == 0 && b == 0)
                break;
            tree[b].push_back(a);
            father[a] = b;
        }

        int t = -1;
        while (father[t] != -1)
        {
            t = father[t];
        }
        dfs(t);
        cout << max(dp[t][1], dp[t][0]) << endl;
    }

    return 0;
}