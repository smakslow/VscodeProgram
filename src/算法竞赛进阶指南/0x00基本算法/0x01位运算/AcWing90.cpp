#include <iostream>
using namespace std;

/* 90. 64位整数乘法
求 a 乘 b 对 p 取模的值。

输入格式
第一行输入整数a，第二行输入整数b，第三行输入整数p。

输出格式
输出一个整数，表示a*b mod p的值。

数据范围
1≤a,b,p≤10^18
输入样例：
3
4
5
输出样例：
2 */
typedef long long LL;
LL a, b, p;
LL mul(LL a, LL b, LL p)
{
    LL ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> a >> b >> p;
    cout << mul(a, b, p) << endl;
    return 0;
}