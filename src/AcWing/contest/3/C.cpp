#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 100010;

int n;
int w[N];
LL tr[N];
vector<int> xs;
LL f[N];

int get(int x)
{
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}

int lowbit(int x)
{
    return x & -x;
}

void add(int x, LL v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] = max(tr[i], v);
}

LL query(int x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res = max(res, tr[i]);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d", &w[i]);
        xs.push_back(w[i]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    LL res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int k = get(w[i]);
        f[i] = query(k - 1) + w[i];
        res = max(res, f[i]);
        add(k, f[i]);
    }

    printf("%lld\n", res);
    return 0;
}