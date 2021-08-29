#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *lchild, *rchild;
} * BitTree;
//将元素插入二叉排序树中
void InsertBitTree(BitTree &T, int x)
{
    if (T == NULL)
    {
        T = new node;
        T->data = x;
        T->lchild = NULL;
        T->rchild = NULL;
        return;
    }
    if (x == T->data)
        return;
    else if (x < T->data)
        InsertBitTree(T->lchild, x);
    else
        InsertBitTree(T->rchild, x);
}
//将二叉树按照先序输出
void PreOrderTraverse(BitTree T)
{
    if (T != NULL)
    {
        cout << T->data << ' ';
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
//将二叉树按照中序输出
void InOrderTraverse(BitTree T)
{
    if (T != NULL)
    {
        InOrderTraverse(T->lchild);
        cout << T->data << ' ';
        InOrderTraverse(T->rchild);
    }
}
//将二叉树按照后序输出
void PostOrderTraverse(BitTree T)
{
    if (T != NULL)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << ' ';
    }
}
int main()
{
    int n, x;
    while (cin >> n)
    {
        BitTree T = NULL;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            InsertBitTree(T, x);
        }
        PreOrderTraverse(T);
        cout << endl;
        InOrderTraverse(T);
        cout << endl;
        PostOrderTraverse(T);
        cout << endl;
    }
    return 0;
}