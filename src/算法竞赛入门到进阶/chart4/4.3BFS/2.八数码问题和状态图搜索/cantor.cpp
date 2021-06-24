#include <bits/stdc++.h>
using namespace std;
/*
  八数码问题：
    在一个3x3棋盘放置编号1-8的8个放快，还有个空格
    任务1：
        指定初始棋局和目标棋局，计算最少的移动次数
    任务2：
        输出数码的移动数列
*/
const int LEN = 362880; //状态共9！种

struct node
{
    int state[9]; //记录一个八数码的排列，即一个状态
    int dis;      //记录到起点的距离
};
int dir[4][2] = {
    {-1, 0}, {0, -1}, {0, 1}, {1, 0} //左上右下
};
int visited[LEN] = {0};
int start[9];
int goal[9];
long int factory[] = {1, 1, 2, 6, 120, 720, 5040, 40320, 362880};
bool Cantor(int str[], int n)
{ // 用康托展开判重
    long result = 0;
    for (int i = 0; i < n; i++)
    {
        int counted = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] > str[j])
                ++counted;
        }
        result += counted * factory[n - i - 1];
    }
    if (!visited[result])
    {
        visited[result] = true;
        return true;
    }
    else
        return false;
}

int bfs()
{
    node head;
    memcpy(head.state, start, sizeof(head.state)); //复制起点的状态
    head.dis = 0;
    queue<node> q;
    Cantor(head.state, 9);
    q.push(head);
    while (!q.empty())
    {
        head = q.front();
        if (memcmp(head.state, goal, sizeof(goal)) == 0)
            return head.dis; //与目标状态对比，相同返回距离
        q.pop();
        int z;
        for (z = 0; z < 9; z++)
        {
            if (head.state[z] == 0)
                break;
        }
        int x = z % 3;
        int y = z / 3;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int newz = newx + 3 * newy;
            if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
            {
                node newnode;
                memcpy(&newnode, &head, sizeof(struct node)); //复制新状态
                swap(newnode.state[z], newnode.state[newz]);
                newnode.dis++;
                if (Cantor(newnode.state, 9))
                    q.push(newnode);
            }
        }
    }
    return -1;
}
int main()
{
    for (int i = 0; i < 9; i++)
        cin >> start[i];
    for (int i = 0; i < 9; i++)
        cin >> goal[i];
    int num = bfs();
    if (num != -1)
        cout << num << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}