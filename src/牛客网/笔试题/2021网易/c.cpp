#include <bits/stdc++.h>

using namespace std;

/* 平分物品
现在有n个物品，每一个物品都有一个价值，现在想将这些物品分给两个人，要求这两个人每一个人分到的物品的价值总和相同
（个数可以不同，总价值相同即可），剩下的物品就需要扔掉，现在想知道最少需要扔多少价值的物品才能满足要求分给两个人。

输入描述:
第一行输入一个整数 T，代表有 T 组测试数据。

对于每一组测试数据，一行输入一个整数 n ，代表物品的个数。

接下来 n 个数，a[i] 代表每一个物品的价值。

1<= T <= 10
1 <= n <= 15
1 <= a[i] <= 100000 */
const int N = 20;
int a[N];
int ans;
void dfs(int p1, int p2, int start, int n, int sum)
{
    if (p1 == p2)
    {
        ans = min(ans, sum - (p1 << 1));
    }
    if (start == n)
        return;

    dfs(p1 + a[start], p2, start + 1, n, sum);
    dfs(p1, p2 + a[start], start + 1, n, sum);
    dfs(p1, p2, start + 1, n, sum);
}
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        ans = INT_MAX;
        dfs(0, 0, 0, n, sum);
        cout << ans << endl;
    }
    return 0;
}