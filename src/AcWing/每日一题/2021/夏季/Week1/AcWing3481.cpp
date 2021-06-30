/* 3481. 阶乘的和
给定一个非负整数 n，请你判断是否存在一些整数 xi，能够使得 n=∑1≤i≤txi!，
其中 t≥1,xi≥0,xi=xj iff i=j。
iff 表示当且仅当。

输入格式
输入包含多组测试数据。

每组数据占一行，包含一个非负整数 n。
最后一行是一个负数，表示输入结束，无需处理。

输出格式
每组数据输出一行结果，如果 n 能表示为若干数的阶乘之和，则输出 YES，否则输出 NO。

数据范围
0≤n≤10^6,
每组输入最多包含 100 组数据。

输入样例：
9
-1
输出样例：
YES */

#include <iostream>
#include <unordered_set>

using namespace std;
int n;
int f[10];
unordered_set<int> s;
void init()
{
    /*  for(int i = 0;i < 10;i++){
        f[i] = 1;
        for(int j = i;j ;j--){
            f[i] *= j;
        }
    } */
    f[0] = 1;
    for (int i = 1; i < 10; i++)
        f[i] = f[i - 1] * i;

    for (int i = 1; i < 1 << 10; i++)
    {
        int x = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i >> j & 1)
                x += f[j];
        }
        s.insert(x);
    }
}
int main()
{
    init();
    while (cin >> n, n >= 0)
    {
        if (s.count(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}