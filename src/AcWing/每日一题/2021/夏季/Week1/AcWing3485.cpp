/* 3485. 最大异或和
给定一个非负整数数列 a，初始长度为 N。
请在所有长度不超过 M 的连续子数组中，找出子数组异或和的最大值。
子数组的异或和即为子数组中所有元素按位异或得到的结果。
注意：子数组可以为空。

输入格式
第一行包含两个整数 N,M。
第二行包含 N 个整数，其中第 i 个为 ai。

输出格式
输出可以得到的子数组异或和的最大值。

数据范围
对于 20% 的数据，1≤M≤N≤100
对于 50% 的数据，1≤M≤N≤1000
对于 100% 的数据，1≤M≤N≤10^5,0≤ai≤2^31−1
输入样例：
3 2
1 2 4
输出样例：
6 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010 * 31, M = 100010;

int n, m;
int s[M];
int son[N][2], cnt[N], idx;

void insert(int x, int v)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
        cnt[p] += v;
    }
}

int query(int x)
{
    int res = 0, p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (cnt[son[p][!u]])
            p = son[p][!u], res = res * 2 + 1;
        else
            p = son[p][u], res = res * 2;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;
    }

    int res = 0;
    insert(s[0], 1);

    for (int i = 1; i <= n; i++)
    {
        if (i > m)
            insert(s[i - m - 1], -1);
        res = max(res, query(s[i]));
        insert(s[i], 1);
    }

    printf("%d\n", res);
    return 0;
}