/* [编程题]朋友圈
现在有107个用户，编号为1- 107，现在已知有m对关系，每一对关系给你两个数x和y，代表编号为x的用户和编号
为y的用户是在一个圈子中，例如：A和B在一个圈子中，B和C在一个圈子中，那么A,B,C就在一个圈子中。现在想知
道最多的一个圈子内有多少个用户。 

输入描述:
第一行输入一个整数T，接下来有T组测试数据。
对于每一组测试数据：第一行输入1个整数n，代表有n对关系。
接下来n行，每一行输入两个数x和y，代表编号为x和编号为y的用户在同一个圈子里。
1 ≤ T ≤ 10
1 ≤ n ≤ 105
1 ≤ x, y ≤ 107

输出描述:
对于每组数据，输出一个答案代表一个圈子内的最多人数

输入例子1:
2
4
1 2
3 4
5 6
1 6
4
1 2
3 4
5 6
7 8

输出例子1:
4
2 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int a[N];
int cnt[N];
void init()
{
    for (int i = 1; i < N; i++)
    {
        a[i] = i, cnt[i] = 0;
    }
}
//路径压缩
int find(int x)
{
    if (x != a[x])
        a[x] = find(a[x]);
    return a[x];
}

void join(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y)
        a[x] = y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int x, y;
        init();
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            join(x, y);
        }
        for (int i = 1; i < N; i++)
            cnt[find(i)]++;
        int ans = -1;
        for (int i = 1; i < N; i++)
            ans = max(ans, cnt[i]);
        cout << ans << endl;
    }
    return 0;
}