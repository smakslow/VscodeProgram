#include <bits/stdc++.h>

using namespace std;
const int MONEY = 251;
int type[5] = {1, 5, 10, 25, 50};
int dp[MONEY] = {0};

void solve()
{

    dp[0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = type[i]; j < MONEY; j++)
        {
            dp[j] = dp[j] + dp[j - type[i]];
        }
    }
}
int main()
{
    int n;
    solve();
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }

    return 0;
}