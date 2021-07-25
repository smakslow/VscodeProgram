#include <map>
#include <iostream>

using namespace std;
const int N = 200010;
int a[N];
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, int> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        int ind = -1;
        for (auto [k, v] : m)
            if (v == 1)
            {
                ind = k;
                break;
            }
        if (ind == -1)
            puts("-1");
        else
            for (int i = 1; i <= n; i++)
                if (ind == a[i])
                {
                    cout << i << endl;
                    break;
                }
    }
    return 0;
}