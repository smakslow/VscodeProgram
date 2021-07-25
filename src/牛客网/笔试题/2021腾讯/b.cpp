/* [编程题]第K小子串
输入一个字符串 s，s 由小写英文字母组成，保证 s 长度小于等于 5000 并且大于等于 1。在 s 的所有不同的子串
中，输出字典序第 k 小的字符串。
字符串中任意个连续的字符组成的子序列称为该字符串的子串。
字母序表示英文单词在字典中的先后顺序，即先比较第一个字母，若第一个字母相同，则比较第二个字母的字典序，
依次类推，则可比较出该字符串的字典序大小。

输入描述:
第一行输出一个字符串 s，保证 s 长度小于等于 5000 大于等于 1。
第二行一个整数 k (1<= k <= 5)，保证 s 不同子串个数大于等于 k。

输出描述:
输出一个字符串表示答案。

输入例子1:
aabb
3

输出例子1:
aab

例子说明1:
不同的子串依次为：
a aa aab aabb ab abb b bb
所以答案为aab */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5002;
char s[N];
int k;
vector<string> v;
int main()
{
    scanf("%s%d", s + 1, &k);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= min(i + k - 1, n); j++)
        {
            string str = "";
            for (int k = i; k <= j; k++)
            {
                str += s[k];
            }
            v.push_back(str);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v[k - 1] << endl;
    return 0;
}