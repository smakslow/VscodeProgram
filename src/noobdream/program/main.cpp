#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    while (cin >> n)
    {
        int m = (n << 1 - 1) >> 1;
        for (int i = m; i >= 0; i--)
        {
            for(int j = 0; j < m; j++){
                cout << ' ';
            }
            
        }
    }
    return 0;
}