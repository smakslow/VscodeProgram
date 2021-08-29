#include <bits/stdc++.h>

using namespace std;

int n;
string str;
bool check(string str)
{
    if (!isalpha(str[0]))
    {
        return false;
    }
    int digit = 0;
    for (int i = 1; i < str.size(); i++)
    {
        if (isdigit(str[i]))
            digit++;
        else if (isalpha(str[i]))
        {
        }
        else
            return false;
    }
    return digit > 0;
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (check(str))
        {
            cout << "Accept" << endl;
        }
        else
            cout << "Wrong" << endl;
    }
    return 0;
}