#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 
牛牛和牛妹最近迷上了新版消消看，该游戏规则如下：

在一个  串中，每一轮，玩家都可以选择一串连续相同字符进行消除，消除之后，左右两侧剩余的字符自动拼接，重新形成一个字符串。
例如：在  中，牛牛选择了第四个和第五个字符，它们连续且都是 ，满足消除条件，而当它们消除之后，左侧剩余的  和右侧剩余的  会拼接到一起，即：消除后剩余的  串为：
计分规则如下：消除了几个  就计几分。
直到消成空串时游戏结束。

对于一串全新的  串，由牛妹先手进行消除，两个人都以最优策略且以得分高为目标进行消除，请问最后，哪个人的得分会比较高？
 */
int main()
{
    vector<int> cnt;
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        string s;
        cin >> s;
        cnt.push_back(0);
        int i = 0;
        for (int k = 0; k < s.size(); k++)
        {
            if (s[k] == '1')
            {
                cnt[i]++;
            }
            else
            {
                while (s[k] == '0')
                    k++;
                k--;
                cnt.push_back(0);
                i++;
            }
        }
        sort(cnt.begin(), cnt.end());
        int score1 = 0, score2 = 0;
        for (int k = cnt.size() - 1; k >= 0; k -= 2)
        {
            score1 += cnt[k];
        }
        for (int k = cnt.size() - 2; k >= 0; k -= 2)
        {
            score2 += cnt[k];
        }
        if (score1 > score2)
        {
            cout << "Niumei" << endl;
            cout << score1 - score2 << endl;
        }
        else if (score1 == score2)
        {
            cout << "Draw" << endl;
        }
        else
        {
            cout << "Niuniu" << endl;
            cout << score2 - score1 << endl;
        }
        cnt.clear();
    }
    return 0;
}