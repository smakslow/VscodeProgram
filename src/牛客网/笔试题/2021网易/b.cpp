#include <bits/stdc++.h>

using namespace std;
int floyd(vector<vector<int>> &graph, int N, int source)
{

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (graph[i][k] != INT_MAX && graph[j][k] != INT_MAX)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
    int ans = INT_MAX;
    for (int i = 1; i <= N; i++)
        ans = min(ans, graph[source][i]);
    return ans == INT_MAX ? -1 : ans;
}
int main()
{
    int N, K, M, v, u, w;
    cin >> N >> K >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 0; i < M; i++)
    {
        cin >> v >> u >> w;
        graph[v][u] == w;
    }
    for (int i = 0; i < N; i++)
        graph[i][i] == 0;
    cout << floyd(graph, N, K) << endl;
    return 0;
}