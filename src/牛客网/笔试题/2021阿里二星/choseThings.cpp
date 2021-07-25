#include <bits/stdc++.h>

using namespace std;
/* [编程题]选择物品
有个物品可供选择，必须选择其中个物品，请按字典序顺序输出所有选取方案的物品编号
与与等被认为是同一种方案，输出字典序最小的即可
输入描述:
对于每一组测试数据， 每行输入个数和。

输出描述:
对于每组输入样例，按字典序输出所有方案选择物品的编号，每种方案占一行

输入例子1:
4 1

输出例子1:
1
2
3
4 */
int n, m;
vector<int> v;
void dfs(int n, int m, int start)
{
    if (v.size() == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        v.push_back(i);
        dfs(n, m, i + 1);
        v.pop_back();
    }
}
int main()
{

    cin >> n >> m;
    dfs(n, m, 1);
    return 0;
}