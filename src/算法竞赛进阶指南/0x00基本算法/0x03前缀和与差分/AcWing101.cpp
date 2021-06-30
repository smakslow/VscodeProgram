#include <iostream>
#include <map>
using namespace std;

map<pair<int, int>, bool> existed; //一条关系可能重复输入
const int N = 10010;
int c[N], d[N]; //
int main()
{
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b); // 假设b大于a
        if (existed[make_pair(a, b)])
            continue;
        d[a + 1]--, d[b]++; //a + 1 ~ b - 1 的数减去1 (a,b中间的牛至少比a,b小1)
        existed[make_pair(a, b)] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        c[i] = c[i - 1] + d[i];
        cout << h + c[i] << endl;
    }
    cout << endl;
    return 0;
}