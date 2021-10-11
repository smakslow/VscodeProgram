#include <bits/stdc++.h>

using namespace std;

stack<int> sorting(stack<int> mystack)
{
    stack<int> ret;
    if (mystack.empty())
        return ret;
    int t = mystack.top();
    mystack.pop();
    while (!mystack.empty() || (!ret.empty() && ret.top() > t))
    {
        if (ret.empty() || t >= ret.top())
        {
            ret.push(t);
            t = mystack.top();
            mystack.pop();
        }
        else
        {
            mystack.push(ret.top());
            ret.pop();
        }
    }
    ret.push(t);
    return ret;
}
stack<int> in;
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        in.push(x);
    }
    stack<int> ret = sorting(in);
    while (!ret.empty())
    {
        cout << ret.top() << endl;
        ret.pop();
    }
    return 0;
}