#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
/* 
3502. 不同路径数
给定一个 n×m 的二维矩阵，其中的每个元素都是一个 [1,9] 之间的正整数。
从矩阵中的任意位置出发，每次可以沿上下左右四个方向前进一步，走过的位置可以重复走。
走了 k 次后，经过的元素会构成一个 (k+1) 位数。
请求出一共可以走出多少个不同的 (k+1) 位数。

输入格式
第一行包含三个整数 n,m,k。

接下来 n 行，每行包含 m 个空格隔开的整数，表示给定矩阵。

输出格式
输出一个整数，表示可以走出的不同 (k+1) 位数的个数。

数据范围
对于 30% 的数据, 1≤n,m≤2,0≤k≤2
对于 100% 的数据，1≤n,m≤5,0≤k≤5,m×n>1
输入样例：
3 3 2
1 1 1
1 1 1
2 1 1
输出样例：
5
样例解释
一共有 5 种可能的 3 位数：

111
112
121
211
212
 */
const int N = 10;

int n, m, k;
int g[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
unordered_set<int> s;
vector<int> v;

void dfs(int a, int b)
{

    if (v.size() == k)
    {
        int num = 0;
        for (int i = 0; i < k; i++)
        {
            num = num * 10 + v[i];
        }
        s.insert(num);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        if (x >= 0 && x < n && y >= 0 && y < m)
        {
            v.push_back(g[x][y]);
            dfs(x, y);
            v.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    k++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs(i, j);

    cout << s.size();
    return 0;
}
