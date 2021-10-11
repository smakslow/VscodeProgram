#include <bits/stdc++.h>

using namespace std;

map<int, int> mp; //first 等级 second id
int main()
{
    int n;
    while (cin >> n && n)
    {
        mp.clear();
        mp[1000000000] = 1; //方丈的标记
        while (n--)
        {
            int id, g; //新和尚id，等级g
            cin >> id >> g;
            mp[g] = id;
            int ans = 0;
            map<int, int>::iterator it = mp.find(g);
            if (it == mp.begin())
                ans = (++it)->second;
            else
            {
                map<int, int>::iterator it2 = it;
                it2--;
                it++;
                if (g - it2->first <= it->second - g)
                    ans = it2->second;
                else
                    ans = it->second;
            }
            cout << id << " " << ans << endl;
        }
    }
    return 0;
}