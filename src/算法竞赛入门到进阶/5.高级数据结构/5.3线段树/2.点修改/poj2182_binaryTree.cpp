#include <iostream>

using namespace std;
/*二叉树实现线段树 */
const int maxn = 10000;
struct
{
    int left, right, len;
} tree[maxn << 2];
int pre[maxn], ans[maxn];
void buildTree(int left, int right, int u)
{
    tree[u].left = left;
    tree[u].right = right;
    tree[u].len = right - left + 1;
    if (left == right)
    {
        return;
    }
    buildTree(left, (left + right) >> 1, u << 1);              //递归左子树
    buildTree(((left + right) >> 1) + 1, right, (u << 1) + 1); //递归右子树
}

int query(int u, int num)
{
    tree[u].len--;
    if (tree[u].left == tree[u].right)
        return tree[u].left;
    if (tree[u << 1].len < num)
        return query((u << 1) + 1, num - tree[u << 1].len);
    else
        return query(u << 1, num);
}
int main()
{
    int n, i;
    cin >> n;
    pre[1] = 0;
    for (int i = 2; i <= n; i++)
        cin >> pre[i];
    buildTree(1, n, 1);
    for (int i = n; i >= 1; i--)
        ans[i] = query(1, pre[i] + 1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}