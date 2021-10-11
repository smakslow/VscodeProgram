#include <iostream>

using namespace std;
const int MONEY = 300;
const int MONTH = 12;
int ans = 0, rest = 0, use;

int main()
{
    for (int i = 1; i <= MONTH; i++)
    {
        cin >> use;
        rest += MONEY - use;
        if (rest < 0)
        {
            cout << -(i) << endl;
            return 0;
        }
        int m = rest / 100;
        ans += m * 100;
        rest -= m * 100;
    }
    cout << ans * 6 / 5 + rest << endl;
    return 0;
}