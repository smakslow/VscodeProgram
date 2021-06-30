#include <iostream>
using namespace std;

/* 89. a^b

求 a 的 b 次方对 p 取模的值。

输入格式
三个整数 a,b,p ,在同一行用空格隔开。

输出格式
输出一个整数，表示a^b mod p的值。

数据范围
0≤a,b≤10^9 
1≤p≤10^9
输入样例：
3 2 7
输出样例：
2 */
int a, b, p;
typedef long long LL;
int power(int a, int b, int p)
{
    int ans = 1 % p;
    while (b)
    {
        if (b & 1)
            ans = (LL)ans * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cin >> a >> b >> p;
    cout << power(a, b, p) << endl;
    return 0;
}