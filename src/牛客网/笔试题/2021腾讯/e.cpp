/* [编程题]队列操作
数据结构基础之一——队列
队列有五种基本操作，插入队尾、取出队首、删除队首、队列大小、清空队列。
现在让你模拟一个队列的操作，具体格式参考输入。

输入描述:
第一行输入一个整数T，表示接下来有T组测试数据。
对于每组测试数据：
第一行输入一个整数Q，表示有Q次操作。
接下来Q行，每行输入一种队列操作方式，具体格式如下：
初始状态下队列为空。

插入队尾：PUSH X
取出队首：TOP//仅仅是看一下队首元素，不要把队首元素删除
删除队首：POP
队列大小：SIZE
清空队列：CLEAR

1<=T<=100
1<=Q,x<=1000
保证操作为以上5种的任意一种。

输出描述:
对于每组测试数据：
如果操作为“取出队首”，输出队首元素，如果无法取出，输出“-1”
如果操作为“删除队首”，如果无法删除，输出“-1”
如果操作为“队列大小”，输出队列大小
其他操作无需输出

输入例子1:
2
7
PUSH 1
PUSH 2
TOP
POP
TOP
POP
POP
5
PUSH 1
PUSH 2
SIZE
POP
SIZE

输出例子1:
1
2
-1
2
1 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
    int T, Q;
    cin >> T;
    while (T--)
    {
        cin >> Q;
        queue<int> q;
        while (Q--)
        {
            string s;
            int x;
            cin >> s;
            if (s == "PUSH")
            {
                cin >> x;
                q.push(x);
            }
            else if (s == "TOP")
            {
                if (q.size())
                    cout << q.front() << endl;
                else
                    puts("-1");
            }
            else if (s == "POP")
            {
                if (q.size())
                    q.pop();
                else
                    puts("-1");
            }
            else if (s == "SIZE")
            {
                cout << q.size() << endl;
            }
            else if (s == "CLEAR")
            {
                while (q.size())
                {
                    q.pop();
                }
            }
        }
    }
    return 0;
}