#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, m, p;
    map<string, int> shop;
    string s;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> s;
        cin >> m;
        while (m--)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> p >> s;
                shop[s] += p;
            }
            int rank = 1;
            map<string, int>::iterator it;
            for (it = shop.begin(); it != shop.end(); it++)
            {
                if (it->second > shop["memory"])
                    rank++;
            }
            cout << rank << endl;
        }
        shop.clear();
    }
    return 0;
}