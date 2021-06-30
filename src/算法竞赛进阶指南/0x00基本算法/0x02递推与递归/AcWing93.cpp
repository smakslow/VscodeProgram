#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> chosen;

void calc(int x)
{
    if (chosen.size() > m || chosen.size() + (n - x + 1) < m) //选择超过m个数 或者选上剩下所有的数都不够m个停止
        return;
    if (x == n + 1)
    {
        for (int i = 0; i < chosen.size(); i++)
            cout << chosen[i] << " ";
        cout << endl;
        return;
    }
    //不选x
    calc(x + 1); //求解子问题
    //选x
    chosen.push_back(x);
    calc(x + 1);       //求解子问题
    chosen.pop_back(); //还原现场
}
int main()
{
    cin >> n >> m;
    calc(1);
    return 0;
}