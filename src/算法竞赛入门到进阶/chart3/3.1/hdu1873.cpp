#include <iostream>
#include <queue>
using namespace std;
/*
priority_queue<Type, Container, Functional>
Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，
但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式
top 访问队头元素
empty 队列是否为空
size 返回队列内元素个数
push 插入元素到队尾 (并排序)
emplace 原地构造一个元素并插入队列
pop 弹出队头元素
swap 交换内容
 //升序队列，小顶堆
 priority_queue <int,vector<int>,greater<int> > q;
 //降序队列，大顶堆
 priority_queue <int,vector<int>,less<int> >q;
*/
int main()
{
    int n;
    while (cin >> n)
    {
        priority_queue<pair<int, int>> q;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        pq.push(4);
        pq.push(3);
        pq.push(5);
        pq.push(1);
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }
    return 0;
}