#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    map<char, int> symbolValue{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(string s)
    {
        // write code here
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int val = symbolValue[s[i]];
            if (i < n - 1 && val < symbolValue[s[i + 1]])
                ans -= val;
            else
                ans += val;
        }
        return ans;
    }
};

int main()
{

    return 0;
}