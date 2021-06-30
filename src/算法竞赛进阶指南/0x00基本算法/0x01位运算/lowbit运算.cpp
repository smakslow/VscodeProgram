#include <bits/stdc++.h>
using namespace std;
/* lowbit(n)定义为非负整数n在二进制表示下“最低位的1及其后边所有的0构成的数值”

lowbit(n) = n &(~n + 1) = n & (-n)

lowbit运算配合hash找出整数二进制表示下所以是1的位

int ans = 0;
while(n){
    n = lowbit(n);
    ans++;
}

GCC编译器内置函数

int _builtin_ctz(unsigned int x)
int _builtin_ctzll(unsigned long long x)
返回x的二进制表示下最低位的1后边有多少个0

int _builtin_popcount(unsigned int x)
int _builtin_popcountll(unsigned long long x)

 */

int lowbit(int n)
{
    return n & (-n);
}

int calc(int n)
{
    int ans = 0;
    while (n)
    {
        n = lowbit(n);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << lowbit(n) << " " << calc(n) << endl;
    return 0;
}