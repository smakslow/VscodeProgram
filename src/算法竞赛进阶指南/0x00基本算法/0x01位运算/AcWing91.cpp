#include <bits/stdc++.h>
using namespace std;

int f[1 << 20][20];
int hamilton(int n, int weight[20][20])
{
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (1 >> j & 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if ((i ^ 1 << j) >> k & 1)
                        f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + weight[k][j]);
                }
            }
        }
    }
    return f[(1 << n) - 1][n - 1];
}
int main()
{
    int n;
    int weight[20][20];
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> weight[i][j];
        }
    }
    cout << hamilton(n, weight) << endl;
    return 0;
}