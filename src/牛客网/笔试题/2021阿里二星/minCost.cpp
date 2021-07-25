#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, a[5005], root, ans = 1e9;
vector<int> e[5005];

void dfs(int r, int f, int deep)
{
    if (r != root && a[r] == a[root])
    {
        ans = min(ans, deep);
    }
    for (int i = 0; i < e[r].size(); i++)
    {
        if (e[r][i] != f)
            dfs(e[r][i], r, deep + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int i, x, y;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
    {
        root = i;
        dfs(i, 0, 0);
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}