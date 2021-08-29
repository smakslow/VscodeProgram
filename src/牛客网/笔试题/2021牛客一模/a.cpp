#include <bits/stdc++.h>

using namespace std;

/* 编程题]刷墙
最近小明搬到了新家，他正在粉刷墙壁，但是不幸的是他粉刷的墙壁并不理想。他的墙壁是一个长度为n的格子，
每个格子用0表示红色，用1表示蓝色。现在墙壁是一个非常混乱的颜色。他想将墙壁涂成左边全是蓝色右边全是红色，
可以将墙壁刷成全是红色或者蓝色。请问他至少需要粉刷多少个格子墙壁刷成他想要的样子？

输入描述:
第一行一个整数。
第二行个长度为的01串，0表示红色，1表示蓝色。

输出描述:
输出一个整数表示最少粉刷次数。

输入例子1:
3
001

输出例子1:
1

例子说明1:
只需要将最后一个刷成红色。 */
int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int lRed = 0, lBlue = 0;
    int rRed = 0, rBlue = 0;
    int mid = (n + 1) >> 1;
    for (int i = 0; i < mid; i++)
    {
        if (str[i] == '0')
            lRed++;
        else
            lBlue++;
    }
    for (int i = mid; i < n; i++)
    {
        if (str[i] == '0')
            rRed++;
        else
            rBlue++;
    }
    int ans = n;
    ans = min(ans, lRed + rBlue);
    ans = min(ans, lRed + rRed);
    ans = min(ans, lBlue + rBlue);
    cout << ans << endl;
    return 0;
}