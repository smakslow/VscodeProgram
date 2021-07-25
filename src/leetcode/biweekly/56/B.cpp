#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
class Solution
{
public:
    int nearestExit(vector<vector<char>> &g, vector<int> &start)
    {
        int n = g.size(), m = g[0].size();
        queue<PII> q;
        q.push({start[0], start[1]});
        g[start[0]][start[1]] = '+';
        int round = 1;
        while (q.size())
        {
            for (int i = 0, siz = q.size(); i < siz; ++i)
            {
                PII u = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d)
                {
                    int x = u.x + dx[d], y = u.y + dy[d];
                    if (x < 0 || x == n || y < 0 || y == m)
                        continue;
                    if (g[x][y] == '+')
                        continue;
                    if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
                        return round;
                    g[x][y] = '+';
                    q.push({x, y});
                }
            }
            round++;
        }
        return -1;
    }
};

int main()
{

    return 0;
}