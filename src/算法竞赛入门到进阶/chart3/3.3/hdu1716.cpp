#include <iostream>
#include <algorithm>
using namespace std;
int arr[4];
int main()
{
    while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3], arr[0] || arr[1] || arr[2] || arr[3])
    {
        sort(arr, arr + 4);
        int pre = arr[0];
        do
        {
            if (arr[0] == 0)
                continue;
            if (arr[0] == pre)
            {
                for (int i = 0; i < 4; i++)
                    cout << arr[i];
            }
            else
            {
                cout << endl;
                for (int i = 0; i < 4; i++)
                    cout << arr[i];
            }
            cout << " ";
            pre = arr[0];
        } while (next_permutation(arr, arr + 4));
        cout << endl;
    }
    return 0;
}