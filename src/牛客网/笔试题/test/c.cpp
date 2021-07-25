#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    int n, a, b, c;
    string str;
    cin >> T;
    while (T--)
    {
        cin >> n >> a >> b >> c;
        cin >> str;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
                x++;
            else
                y++;
        }
        int ans = a * x + b * y;
        ans = min(ans, (x + y) * a + y * c);
        ans = min(ans, (x + y) * b + x * c);
        cout << ans << endl;
    }
    return 0;
}