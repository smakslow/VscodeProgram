#include <iostream>

using namespace std;
const int N = 10;
char g[N][N];
bool col[N];
int n, k, ans;

void dfs(int row, int cnt)
{
    if (row > n)
    {
        if (cnt == k)
            ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (g[row][i] == '#' && !col[i])
        {
            col[i] = 1;
            dfs(row + 1, cnt + 1);
            col[i] = 0;
        }
    }
    dfs(row + 1, cnt);
}
int main()
{
    while (cin >> n >> k, ~n)
    {
        for (int i = 0; i < n; i++)
            cin >> g[i];
        ans = 0;
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}