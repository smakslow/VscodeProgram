#include <bits/stdc++.h>
using namespace std;
/*
https://loj.ac/p/10022
*/

typedef long long ll;
ll a[1010], s[1010], maxd;
inline ll max(ll x, ll y)
{
    return x > y ? x : y; //最大值
}
inline ll get(ll aa, ll bb)
{
    return bb / aa + 1; //函数函数
}
ll gcd(ll aa, ll bb)
{
    return (!bb) ? aa : gcd(bb, aa % bb); //最大公约数
}
bool bijiao(ll x)
{
    for (ll i = x; i >= 0; i--)
        if (a[i] != s[i])
            return s[i] < 0 || a[i] < s[i];

    return false;
}
bool dfs(ll k, ll fa, ll aa, ll bb)
{
    if (k == maxd)
    {
        if (bb % aa)
            return false;

        a[k] = bb / aa;

        if (bijiao(k))
        {
            for (ll i = 0; i <= k + 1; i++)
            {
                s[i] = a[i];
            }
        }

        return true;
    }
    else
    {
        bool bk = false;
        fa = max(fa, get(aa, bb));

        for (ll i = fa;; i++)
        {
            if ((maxd + 1 - k) * bb <= aa * i)
                break;

            a[k] = i;
            ll ax = aa * i - bb, bx = bb * i;
            ll gg = gcd(ax, bx);

            if (dfs(k + 1, i + 1, ax / gg, bx / gg))
                bk = true;
        }

        return bk;
    }
}
int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    bool bk = false;

    for (maxd = 1; maxd <= 100; maxd++)
    {
        memset(s, -1, sizeof(s));

        if (dfs(0, get(a, b), a, b))
        {
            bk = true;
            break;
        }
    }

    if (bk)
    {
        for (ll i = 0; i < maxd; i++)
            printf("%lld ", s[i]);

        printf("%lld\n", s[maxd]);
    }

    return 0;
}