#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    double ans = 0;
    int idx = 1;
    while (true)
    {
        if (ans > k)
        {
            cout << idx - 1 << endl;
            return 0;
        }
        ans += 1.0/idx;
        ++idx;
    }
    return 0;
}