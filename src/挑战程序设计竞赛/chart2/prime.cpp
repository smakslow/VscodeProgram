#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6;
int prime[MAX_N]; // 第i个素数
bool isPrime[MAX_N + 1];

//返回n以内的素数（埃氏筛法）
int sieve(int n)
{
    int p = 0;
    for (int i = 0; i <= n; i++)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            prime[p++] = i; //依次将2，3，5，7的倍数消除
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return p;
}
int main()
{
    int N;
    cin >> N;
    cout << sieve(N);
    return 0;
}