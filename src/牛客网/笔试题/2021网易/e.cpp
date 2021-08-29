#include <vector>
#include <iostream>

using namespace std;

void Tarjan(vector<vector<int>> &G, vector<int> &low, vector<int> &dfn, vector<bool> &visited, vector<int> &st, int &time, int &res, int index)
{
    st.push_back(index);
    //标记入栈的节点
    visited[index] = true;
    dfn[index] = low[index] = time++;
    //对index所连通的点进行访问
    for (auto v : G[index])
    {
        //若index所联通的v点尚未被访问，则对其进行访问,访问后可能得到更低的low值，则可以更新index的low值
        if (!dfn[v])
        {
            Tarjan(G, low, dfn, visited, st, time, res, v);
            low[index] = min(low[index], low[v]);
        }
        //若此节点被访问过，且在栈中，则有可能可以更新index的low值
        else if (visited[v])
        {
            low[index] = min(low[index], low[v]);
        }
        //若此节点被访问过但不在栈中，则无需操作，为单独的一个强连通分量，不可能与index形成强连通分量
    }
    //若遍历完index的所有连通的节点后，并不能更新low[index]的时间戳，则表示index自身就是一个强连通分量的顶点
    if (dfn[index] == low[index])
    {
        int cnt = 0;
        int tmp;
        do
        {
            tmp = st.back();
            st.pop_back();
            visited[tmp] = false;
            ++cnt;
        } while (tmp != index);
        res += cnt * (cnt - 1) / 2;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int src, dst;
        cin >> src >> dst;
        G[src].push_back(dst);
    }

    int time = 0;
    //low[i]存放i节点由有向图可回溯到的最早时间戳
    vector<int> low(n + 1);
    //dfn[i]表示i点被访问到的真实时间戳
    vector<int> dfn(n + 1);
    //标记该节点是否在栈中
    vector<bool> visited(n + 1, false);
    //vector模拟栈
    vector<int> st;
    //存储结果
    int res = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        //若此前未访问过此节点，则访问
        if (!dfn[i])
            Tarjan(G, low, dfn, visited, st, time, res, i);
    }
    cout << res << endl;
    return 0;
}