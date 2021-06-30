#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> chosen;

void calc(int x)
{
    if (x == n + 1)
    {
        for (int i = 0; i < chosen.size(); i++)
            cout << chosen[i] << " ";
        cout << endl;
        return;
    }
    //不选x
    calc(x + 1);//求解子问题
    //选x
    chosen.push_back(x);
    calc(x + 1);//求解子问题
    chosen.pop_back();//还原现场
}
int main()
{
    cin >> n;
    calc(1);
    return 0;
}