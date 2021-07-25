#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n, x;
    unordered_map<int, ll> m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        m[x - i] += x;
    }
    ll ans = 0;
    for (unordered_map<int, ll>::iterator it = m.begin(); it != m.end(); it++)
    {
        ans = max(ans, it->second);
    }
    cout << ans << endl;
    return 0;
}