#include <bits/stdc++.h>

using namespace std;
const int N = 1001;
int a[N][3];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    int index = 0;
    int t = 1e9;
    for (int i = 0; i < 3; i++)
    {
        if (a[0][i] <= t)
        {
            t = a[0][i];
            index = i;
        }
    }
    ans += t;
    for (int i = 1; i < n; i++)
    {
        t = 1e9;
        int f = 0;
        for (int j = 0; j < 3; j++)
        {

            if (j != index && a[i][j] <= t)
            {
                t = a[i][j];
                f = j;
            }
        }
        index = f;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}