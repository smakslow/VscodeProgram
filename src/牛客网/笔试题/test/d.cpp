#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            if (str[i] == '(')
            {
                st.push(str[i]);
            }
            else
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(str[i]);
                }
            }
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    if (st.empty())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}