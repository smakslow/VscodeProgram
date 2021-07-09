#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
ll dp[N], siz[N];
ll inv[N], fac[N], ifac[N];
vector<int> edges[N];
class Solution
{
public:
    ll C(int n, int m)
    {
        return fac[n] * ifac[m] % M * ifac[n - m] % M;
    }

    ll dfs(int x, int fa)
    {
        siz[x] = 0;
        dp[x] = 1;
        for (int v : edges[x])
        {
            dfs(v, x);
            dp[x] = dp[x] * dp[v] % M;
            dp[x] = dp[x] * C(siz[x] + siz[v], siz[v]) % M;
            siz[x] += siz[v];
        }
        siz[x]++;
        return dp[x];
    }
    int waysToBuildRooms(vector<int> &prevRoom)
    {
        int n = prevRoom.size();
        inv[1] = inv[0] = fac[0] = ifac[0] = 1;
        for (int i = 2; i <= n; i++)
            inv[i] = 1ll * (M - M / i) * inv[M % i] % M;
        for (int i = 1; i <= n; i++)
        {
            fac[i] = fac[i - 1] * i % M;
            ifac[i] = ifac[i - 1] * inv[i] % M;
        }
        for (int i = 0; i <= n; i++)
        {
            edges[i].clear();
            siz[i] = 0;
        }
        for (int i = 1; i < n; i++)
            edges[prevRoom[i]].push_back(i);
        return dfs(0, -1);
    }
};
int main()
{

    return 0;
}