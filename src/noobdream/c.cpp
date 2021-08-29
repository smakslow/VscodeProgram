#include <bits/stdc++.h>

using namespace std;

int solve(int m, int n, int pre)
{
    if ((m == 0 && n > 0) || (n == 0 && m > 0))
        return 0;
    else if (m == 0 && n == 0)
        return 1;

    int count = 0;

    for (int i = pre; i <= pre + 3; i++)
    {
        count += search(m - 1, n - i, i);
    }
    return count;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
        count += solve(m - 1, n - i, i);
    cout << count << endl;
}
