#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a = 0, b = 0;
        while (n--)
        {
            int x;
            cin >> x;
            if (x & 1)
                a++;
            else
                b++;
        }
        if (a == 0 || b == 0)
            puts("YES");
        else
            puts("NO");
    }
}
