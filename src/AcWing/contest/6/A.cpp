#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int even = 0, odd = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x & 1)
            odd++;
        else
            even++;
    }
    if (odd & 1)
        cout << odd << endl;
    else
        cout << even << endl;
    return 0;
}
