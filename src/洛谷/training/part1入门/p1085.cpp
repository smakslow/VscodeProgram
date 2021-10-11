#include <iostream>

using namespace std;

const int weekend = 7;
int school, mom;
int main()
{
    int ans = 0, last = 0;
    for (int i = 1; i <= weekend; i++)
    {
        cin >> school >> mom;
        int sum = school + mom;
        if (sum > 8)
        {
            if (sum > last)
            {
                ans = i;
                last = sum;
            }
        }
    }
    cout << ans << endl;
    return 0;
}