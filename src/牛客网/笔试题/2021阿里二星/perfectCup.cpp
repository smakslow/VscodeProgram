#include <bits/stdc++.h>

using namespace std;
/* [编程题]完美对
有个物品，每个物品有个属性，第件物品的第个属性用一个正整数表示记为，
两个不同的物品被称为是完美对的当且仅当，求完美对的个数。
输入描述:
第一行两个数字。
接下来n行，第i行k个数字表示ai,1 - ai,k。

输出描述:
一行一个数字表示答案

输入例子1:
5 3
2 11 21
19 10 1
20 11 1
6 15 24
18 27 36

输出例子1:
3 */
typedef long long ll;
map<vector<int>, int> mp;

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> vec(k - 1, 0);
            int fv, v;
            cin >> fv;
            for (int j = 1; j < k; j++)
            {
                cin >> v;
                vec[j - 1] = v - fv;
            }
            mp[vec]++;
        }
        ll result = 0;
        vector<int> neg(k - 1, 0);
        if (mp.find(neg) != mp.end())
        {
            ll cnt = mp[neg];
            result += cnt * (cnt - 1) / 2;
            mp.erase(neg);
        }
        ll pcnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            for (size_t i = 0; i < it->first.size(); i++)
            {
                neg[i] = -it->first[i];
            }
            if (mp.find(neg) != mp.end())
            {
                ll cnt = mp[neg];
                pcnt += cnt * it->second;
            }
        }
        result += pcnt / 2;
        cout << result << endl;
    }
    return 0;
}
