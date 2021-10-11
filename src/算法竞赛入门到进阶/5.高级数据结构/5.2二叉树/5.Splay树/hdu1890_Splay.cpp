#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int root;
int rev[maxn], pre[maxn], tot[maxn];
//rev[i]标记i被翻转；pre[i] i的父结点；tot[i]，i的子树上结点的个数
int tree[maxn][2];
//tree[i][0] 左孩子 tree[i][1]右孩子
struct node
{
    int val, id;
    bool operator<(const node &A) const
    {
        if (val == A.val)
            return id < A.id;
        return val < A.val;
    }

} node[maxn];

void pushup(int x)
{
    tot[x] = tot[tree[x][0]] + tot[tree[x][1]] + 1;
}

void update_rev(int x)
{
    if (!x)
        return;
    swap(tree[x][0], tree[x][1]);
    rev[x] ^= 1;
}

void pushdown(int x)
{
    if (rev[x])
    {
        update_rev(tree[x][0]);
        update_rev(tree[x][1]);
        rev[x] = 0;
    }
}

void rotate(int x, int c)
{ //c = 0 左旋， c = 1右旋
    int y = pre[x];
    pushdown(y);
    pushdown(x);
    tree[y][!c] = tree[x][c];
    pre[tree[x][c]] = y;
    if (pre[y])
        tree[pre[y]][tree[pre[y]][1] == y] = x;
    pre[x] = pre[y];
    tree[x][c] = y;
    pre[y] = x;
    pushup(y);
}

void splay(int x, int goal)
{ //将结点x旋转为goal的儿子，如果goal为0，则旋转到根

    pushdown(x);
    while (pre[x] != goal)
    {
        if (pre[pre[x]] == goal)
        {
            pushdown(pre[x]);
            pushdown(x);
            rotate(x, tree[pre[x]][0] == x);
        }
        else
        {
            pushdown(pre[pre[x]]);
            pushdown(pre[x]);
            pushdown(x);
            int y = pre[x];
            int c = (tree[pre[y]][0] == y);
            if (tree[y][c] == x)
            {
                rotate(x, !c);
                rotate(x, c);
            }
            else
            {
                rotate(y, c);
                rotate(x, c);
            }
        }
    }
    pushup(x);
    if (!goal)
        root = x;
}
int main(int argc, char **argv)
{
    int n;
    cin >> n;
    return 0;
}