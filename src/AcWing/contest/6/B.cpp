#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> S;

void dfs(int u, LL x)
{
    S.push_back(x);
    if (u == 10)
        return;
    dfs(u + 1, x * 10 + 4);
    dfs(u + 1, x * 10 + 7);
}

int main()
{
    dfs(0, 0);
    sort(S.begin(), S.end());

    LL l, r;
    cin >> l >> r;
    LL res = 0;
    for (int i = 1; i < S.size(); i++)
    {
        LL a = S[i - 1] + 1, b = S[i];
        res += S[i] * max(0ll, (min(r, b) - max(l, a) + 1));
    }
    cout << res << endl;

    return 0;
}
