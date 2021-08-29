#include <bits/stdc++.h>

using namespace std;
const int N = 110;
int dp[N];
int main()
{
    string str;
    cin >> str;
    int n = str.size();
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        if (str[i] == '1')
        {
            if (i + 2 <= n)
                dp[i] += dp[i + 2];
            if (i + 3 <= n)
                dp[i] += dp[i + 3];
        }
    }
    cout << dp[0] << endl;
    return 0;
}