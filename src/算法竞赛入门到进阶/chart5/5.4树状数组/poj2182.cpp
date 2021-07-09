#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e4;

int tree[MAX], pre[MAX], ans[MAX];
int n;

#define lowbit(x) (x & (-x))

void add(int x, int d)
{
    while (x <= n)
    {
        tree[x] += d;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int findpos(int x)
{
    int left = 1, right = n;
    while (left < right)
    {
        int mid = left + (right - left) >> 1;
        if (sum(mid) < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        return left;
    }
}

int main()
{
    cin >> n;
    pre[1] = 0;
    for (int i = 2; i <= n; i++)
        cin >> pre[i];

    for (int i = 1; i <= n; i++)
        tree[i] = lowbit(i);
    for (int i = n; i > 0; i--)
    {
        int x = findpos(pre[i] + 1);
        add(x, -1);
        ans[i] = x;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}