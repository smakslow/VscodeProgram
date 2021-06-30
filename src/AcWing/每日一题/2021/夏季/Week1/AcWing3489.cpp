/* 3489. 星期几
已知 1 年 1 月 1 日是星期一。现在给定一个日期，请你判断是星期几。
注意闰年的 2 月有 29 天。
满足下面条件之一的是闰年：
年份是 4 的整数倍，而且不是 100 的整数倍；年份是 400 的整数倍。
输入格式
输入包含多组测试数据。

每组数据占一行，包含一个整数 d 表示日，一个字符串 m 表示月，一个整数 y 表示年。
月份 1∼12，依次如下所示：
January, February, March, April, May, June, July, August, September, October, November, December
输出格式
每组数据输出一行结果，输出一个字符串表示给定日期是星期几。

周一至周日依次如下所示：
Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
数据范围
1000≤y≤3000,
给定日期保证合法。
每个输入最多包含 100 组数据。

输入样例：
9 October 2001
14 October 2001
输出样例：
Tuesday
Sunday */

#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int months[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31,
    30, 31, 30, 31};
unordered_map<string, int> month_name = {
    {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}};
string week_name[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int day, month, year;
string str;

bool is_leap(int year)
{
    return !(year % 4) && year % 100 || !(year % 400);
}

int get_days(int year, int month)
{
    int s = months[month];
    if (month == 2 && is_leap(year))
        return s + 1;
    return s;
}
int main()
{
    while (cin >> day >> str >> year)
    {
        month = month_name[str];
        int i = 1, j = 1, k = 1;
        int days = 0;
        while (i < year || j < month || k < day)
        {
            k++, days++;
            if (k > get_days(i, j))
            {
                k = 1;
                j++;
                if (j > 12)
                {
                    j = 1;
                    i++;
                }
            }
        }
        cout << week_name[days % 7] << endl;
    }
    return 0;
}