#include <iostream>
#include <vector>

using namespace std;
/* 
把1-n这n(n < 10)个整数排成一行后随即打乱顺序，输出所有可能的次序
 */
int order[20];   //按顺序依次记录被选择的整数
bool chosen[20]; //标记是否被选择
int n;
void calc(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", order[i]);
        puts(" ");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (chosen[i])
            continue;
        order[k] = i;
        chosen[i] = 1;
        calc(k + 1);
        chosen[i] = 0;
        order[k] = 0;
    }
}
int main()
{
    scanf("%d",&n);
    calc(1);
    return 0;
}