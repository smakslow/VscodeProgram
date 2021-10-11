#include <iostream>

using namespace std;

int n;
int num, price;
int ans = 0x3f3f3f3f;
int main()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> num >> price;
        if (n % num)
        {
            num = n / num + 1;
        }
        else
            num = n / num;
        ans = min(num * price, ans);
    }
    cout << ans << endl;
    return 0;
}