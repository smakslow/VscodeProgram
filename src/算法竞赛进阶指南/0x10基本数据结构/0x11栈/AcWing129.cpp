#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n, cnt = 20;//输出前20个
vector<int> state1;
stack<int> state2;
int state3 = 1;
void dfs()
{
    if (!cnt)            //已输出前20个结束
        return;
    if (state1.size() == n) //n个数已经进出栈
    {
        cnt--;
        for (auto x : state1)
            cout << x;
        cout << endl;
        return;
    }
    if (!state2.empty()) //栈不为空时
    {
        state1.push_back(state2.top());
        state2.pop();
        dfs();
        state2.push(state1.back());
        state1.pop_back();
    }
    if (state3 <= n)
    {
        state2.push(state3);
        state3++;
        dfs();
        state3--;
        state2.pop();
    }
}

int main()
{
    cin >> n;
    dfs();
    return 0;
}