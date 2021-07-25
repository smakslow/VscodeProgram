#include <bits/stdc++.h>

using namespace std;
/* 小强想要从[1,A]中选出一个整数x,从[1,B]中选出一个整数y.使得满足x/y =  a/ b的同时且x和y的乘积最大。
如果不存在这样的x和y,请输出“ 0 0”.
输入描述:
输入一行包含四个整数A,B,a和b.

输出描述:
输出两个整数表示满足条件的和.若不存在，则输出"0 0".

输入例子1:
1 1 2 1

输出例子1:
0 0

输入例子2:
1000 500 4 2

输出例子2:
1000 500 */
int A, B, a, b;
int gcd(int a, int b)
{
    int c = 0;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    cin >> A >> B >> a >> b;
    int c = gcd(a, b);
    a /= c;
    b /= c;
    long x, y;
    if (A < a || B < b)
    {
        x = 0, y = 0;
    }
    else
    {
        x = a;
        y = b;
        while (x + a <= A && y + b <= B)
        {
            x += a;
            y += b;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}