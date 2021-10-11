#include <bits/stdc++.h>

using namespace std;
const int COIN = 101;
const int MONEY = 251;
int type[5] = {1, 5, 10, 25, 50};
int dp[MONEY][COIN] = {0};

void solve()
{

    dp[0][0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < COIN; j++)
        {
            for (int k = type[i]; k < MONEY; k++)
            {
                dp[k][j] += dp[k - type[i]][j - 1];
            }
        }
    }
}
int main()
{
    int n;
    solve();
    int ans[MONEY] = {0};
    for (int i = 0; i < MONEY; i++)
    {
        for (int j = 0; j < COIN; j++)
        {
            ans[i] += dp[i][j];
        }
    }
    while (cin >> n)
    {
        cout << ans[n] << endl;
    }

    return 0;
}