#include <iostream>

using namespace std;

const int N = 10010;
int a[N];
int n, m;            //将n本书分成连续的m组
bool valid(int size) //检查每组厚度之和小于size
{
    int group = 1, rest = size; //初始分组group为一组，剩余rest厚度还未使用
    for (int i = 1; i <= n; i++)
    {
        if (rest >= a[i]) //剩余厚度rest大于第i本书厚度时
            rest -= a[i];
        else ////剩余厚度rest小于第i本书厚度时，新增分组，新的剩余厚度为最大值size - 当前已分配a[i];
            group++, rest = size - a[i];
    }
    return group <= m;
}

//把它们分成连续的M组，使T最小化，其中T表示厚度之和最大的一组的厚度
//二分答案，判断每组厚度之和不超过二分的值时，能否在m组内把书分完
int calc(int l, int r)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (valid(mid)) //如果符合条件
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r += a[i];
    }
    cout << calc(l, r) << endl;
    return 0;
}