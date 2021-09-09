#include <bits/stdc++.h>

using namespace std;

/* islower(char c) ：是否为小写字母
isupper(char c)： 是否为大写字母
isdigit(char c) ：是否为数字
isalpha(char c) ：是否为字母
isalnum(char c)： 是否为字母或者数字
toupper(char c)： 字母小转大
tolower(char c) ：字母大转小 */
int main()
{
    string s;
    cin >> s;
    string type1 = "", type2 = "", type3 = "", type4 = "";
    int n = s.size();
    bool sign = false;
    type1.push_back(toupper(s[0]));
    type2.push_back(tolower(s[0]));
    type3.push_back(tolower(s[0]));
    type4.push_back(tolower(s[0]));
    for (int i = 1; i < n; ++i)
    {
        if (isupper(s[i]) || sign)
        {
            type1.push_back(toupper(s[i]));
            type2.push_back(toupper(s[i]));
            if (!sign)
                type3.push_back('_');
            type3.push_back(tolower(s[i]));
            if (!sign)
                type4.push_back('-');
            type4.push_back(tolower(s[i]));
            sign = false;
        }
        else if (s[i] == '_' || s[i] == '-')
        {
            type3.push_back('_');
            type4.push_back('-');
            sign = true;
        }
        else
        {
            type1.push_back(s[i]);
            type2.push_back(s[i]);
            type3.push_back(s[i]);
            type4.push_back(s[i]);
            sign = false;
        }
    }

    cout << type1 << ' ' << type2 << ' ' << type3 << ' ' << type4 << endl;

    return 0;
}