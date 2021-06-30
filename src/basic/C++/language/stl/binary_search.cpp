#include <bits/stdc++.h>

using namespace std;

int a[10005];
int main()
{
    ios::sync_with_stdio(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cin >> x;
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = ((right - left) >> 1) + left;
        if (a[mid] == x)
        {
            cout << "find" << endl;
            return 0;
        }
        else if (a[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << "not find" << endl;
    return 0;
}