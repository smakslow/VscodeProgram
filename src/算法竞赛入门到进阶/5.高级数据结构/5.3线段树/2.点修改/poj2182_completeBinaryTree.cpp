#include <iostream>
#include <cmath>

using namespace std;
const int maxn = 10000;
int pre[maxn] = {0}, tree[maxn << 2] = {0}, ans[maxn] = {0};

void buildTree(int n, int last_left)
{
    int i;
    for (i = last_left; i < last_left + n; i++) //给二叉树的最后一行赋值，左边n个结点是n头牛
    {
        tree[i] = 1;
    }
    while (last_left != 1)
    {
        for (i = last_left >> 1; i < last_left; i++)
        {
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
        last_left >>= 1;
    }
}

int query(int u, int num, int last_left)
{
    tree[u]--;
    if (tree[u] == 0 && u >= last_left)
        return u;
    if (tree[u << 1] < num)
        return query((u << 1) + 1, num - tree[u << 1], last_left);
    else
        return query(u << 1, num, last_left);
}

int main()
{
    int n, last_left, i;
    cin >> n;
    pre[1] = 0;
    last_left = 1 << (int(log(n) / log(2)) + 1);
    for (int i = 2; i <= n; i++)
        cin >> pre[i];
    buildTree(n, last_left);
    for (int i = n; i >= 1; i--)
        ans[i] = query(1, pre[i] + 1, last_left) - last_left + 1;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}