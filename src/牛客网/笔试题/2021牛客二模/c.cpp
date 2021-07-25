#include <iostream>
#include <vector>
using namespace std;
class Tree
{
public:
    Tree(){};
    bool isEnd = false;
    int index = 0;
    Tree *nextTree[10];
};
int DFS(Tree *tree, vector<char> &myvec)
{
    if (tree->isEnd == true)
        return 1;
    int count = 0;
    for (auto ch : myvec)
    {
        if (tree->nextTree[ch - '0'] != NULL)
        {
            count += DFS(tree->nextTree[ch - '0'], myvec);
        }
    }
    return count;
}

int main()
{
    int n, Q;
    while (cin >> n >> Q)
    {
        Tree *root = new Tree();
        vector<char> myvec{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            Tree *tree = root;
            for (auto ch : str)
            {
                if (tree->nextTree[ch - '0'] == NULL)
                {
                    tree->nextTree[ch - '0'] = new Tree();
                }
                tree->isEnd = false;
                tree = tree->nextTree[ch - '0'];
            }
            tree->isEnd = true;
            tree->index = i;
        }
        for (int i = 0; i < Q; i++)
        {
            string str;
            cin >> str;
            int count = 0;
            Tree *tree = root;
            int num = 0;
            for (auto ch : str)
            {
                if (tree->nextTree[ch - '0'] != NULL)
                {
                    tree = tree->nextTree[ch - '0'];
                    count++;
                }
                else
                {

                    for (auto ch : myvec)
                    {
                        if (tree->nextTree[ch - '0'] != NULL)
                        {
                            num += DFS(tree->nextTree[ch - '0'], myvec);
                        }
                    }
                    break;
                }
            }
            cout << count << " " << num << endl;
        }
    }
    return 0;
}
