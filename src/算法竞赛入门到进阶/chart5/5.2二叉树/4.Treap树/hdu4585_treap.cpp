#include <bits/stdc++.h>

using namespace std;

const int N = 5000010;
int a[N];
struct Node
{
    int size; //以这个结点为根的子树的结点总数量
    int rank;
    int key;
    Node *son[2]; // son[0]左孩子  son[1]右孩子
    bool operator<(const Node &a)
    {
        return rank < a.rank;
    }

    int cmp(int x) const
    {
        if (x == key)
            return -1;
        return x < key ? 0 : 1;
    }

    void update() //更新size
    {
        size = 1;
        if (son[0] != NULL)
            size += son[0]->size;
        if (son[1] != NULL)
            size += son[1]->size;
    }
};

void rotate(Node *&o, int d) //d = 0 左旋，d = 右旋
{
    Node *k = o->son[d ^ 1];
    o->son[d ^ 1] = k->son[d];
    k->son[d] = o;
    o->update();
    k->update();
    o = k;
}

void insert(Node *&o, int x)
{
    if (o == NULL)
    {
        o = new Node();
        o->son[0] = o->son[1] = NULL;
        o->key = x;
        o->rank = rand();
        o->size = 1;
    }
    else
    {
        int d = o->cmp(x);
        insert(o->son[d], x);
        o->update();
        if (o < o->son[d])
            rotate(o, d ^ 1);
    }
}

int kth(Node *o, int k) //返回第k大的数
{
    if (o == NULL || k <= 0 || k > o->size)
        return -1;
    int s = o->son[1] == NULL ? 0 : o->son[1]->size;
    if (k == s + 1)
        return o->key;
    else if (k <= s)
        return kth(o->son[1], k);
    else
        return kth(o->son[0], k - s - 1);
}

int find(Node *o, int x) //返回元素x的名次
{
    if (o == NULL)
        return -1;
    int d = o->cmp(x);
    if (d == -1) // x == key
        return o->son[1] == NULL ? 1 : o->son[1]->size + 1;
    else if (d == 1) // x > key
        return find(o->son[d], x);
    else //x < key
    {
        int tmp = find(o->son[d], x);
        if (tmp == -1)
            return -1;
        else
            return o->son[1] == NULL ? tmp + 1 : tmp + 1 + o->son[1]->size;
    }
}
int main()
{
    int n;
    while (cin >> n && n)
    {
        srand(time(NULL));
        int id, g;
        cin >> id >> g;
        Node *root = new Node();
        root->son[0] = root->son[1] = NULL;
        root->rank = rand();
        root->key = g;
        root->size = 1;
        a[g] = id;
        cout << id << " " << 1 << endl;
        for (int i = 2; i <= n; i++)
        {
            cin >> id >> g;
            a[g] = id;
            insert(root, g);
            int t = find(root, g);
            int ans1, ans2, ans;
            ans1 = kth(root, t - 1);
            ans2 = kth(root, t + 1);
            if (ans1 != -1 && ans2 != -1)
                ans = ans1 - g >= g - ans2 ? ans2 : ans1;
            else if (ans1 == -1)
                ans = ans2;
            else
                ans = ans1;
            cout << id << " " << a[ans] << endl;
        }
    }
    return 0;
}