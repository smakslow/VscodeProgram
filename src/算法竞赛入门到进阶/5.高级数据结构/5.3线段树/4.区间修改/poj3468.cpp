#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
ll sum[maxn << 2], add[maxn << 2];

void push_up(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; //rt << 1为偶数，(rt << 1 | 1) = (rt << 1 + 1)
}

void push_down(int rt, int m)
{
    if (add[rt])
    {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt << 1] += (m - (m >> 1)) * add[rt];
        add[rt << 1 | 1] += (m >> 1) * add[rt];
        add[rt] = 0;
    }
}

#define lson left, mid, rt << 1
#define rson mid + 1, right, rt << 1 | 1
void build(int left, int right, int rt)
{
    add[rt] = 0;
    if (left == right)
    {
        cin >> sum[rt];
        return;
    }

    int mid = left + (right - left) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int a, int b, ll c, int left, int right, int rt)
{
    if (a <= left && b >= right)
    {
        sum[rt] += (right - left + 1) * c;
        add[rt] += c;
        return;
    }
    push_down(rt, right - left + 1);
    int mid = left + (right - left) >> 1;
    if (a <= mid)
        update(a, b, c, lson);
    if (b > mid)
        update(a, b, c, rson);
    push_up(rt);
}

ll query(int a, int b, int left, int right, int rt)
{
    if (a <= left && b >= right)
        return sum[rt];
    push_down(rt, right - left + 1);
    int mid = left + (right - left) >> 1;
    ll ans = 0;
    if (a <= mid)
        ans += query(a, b, lson);
    if (b > mid)
        ans += query(a, b, rson);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    build(1, n, 1);
    while (m--)
    {
        string str;
        int a, b;
        ll c;
        cin >> str;
        if (str[0] == 'C')
        {
            cin >> a >> b >> c;
            update(a, b, c, 1, n, 1);
        }
        else
        {
            cin >> a >> b;
            cout << query(a, b, 1, n, 1) << endl;
        }
    }

    return 0;
}