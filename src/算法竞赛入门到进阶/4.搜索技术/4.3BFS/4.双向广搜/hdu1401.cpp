#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); cout.tie(0);
#include <cstdio>   //sprintf islower isupper
#include <cstdlib>  //malloc  exit strcat itoa system("cls")
#include <iostream> //pair
#include <fstream>  //freopen("C:\\Users\\13606\\Desktop\\Input.txt","r",stdin);
#include <bitset>
//#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <set>
#include <string.h> //strstr substr strcat
#include <string>
#include <time.h> // srand(((unsigned)time(NULL))); Seed n=rand()%10 - 0~9;
#include <cmath>
#include <deque>
#include <queue>  //priority_queue<int, vector<int>, greater<int> > q;//less
#include <vector> //emplace_back
//#include <math.h>
#include <cassert>
#include <iomanip>
//#include <windows.h>//reverse(a,a+len);// ~ ! ~ ! floor
#include <algorithm> //sort + unique : sz=unique(b+1,b+n+1)-(b+1);+nth_element(first, nth, last, compare)
using namespace std; //next_permutation(a+1,a+1+n);//prev_permutation

clock_t __START, __END;
double __TOTALTIME;
void _MS() { __START = clock(); }
void _ME()
{
    __END = clock();
    __TOTALTIME = (double)(__END - __START) / CLOCKS_PER_SEC;
    cout << "Time: " << __TOTALTIME << " s" << endl;
}

#define rint register int
#define fo(a, b, c) for (rint a = b; a <= c; ++a)
#define fr(a, b, c) for (rint a = b; a >= c; --a)
#define mem(a, b) memset(a, b, sizeof(a))
#define pr printf
#define sc scanf
#define ls rt << 1
#define rs rt << 1 | 1
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const double E = 2.718281828;
const double PI = acos(-1.0);
const ll INF = (1LL << 60);
const int inf = (1 << 30);
const double ESP = 1e-9;
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 10;

int mp[10][10];
unordered_map<ull, bool> mark;
struct node
{
    ull id;
    int step;
};
ull get()
{
    ull now = 0, temp = 1;
    int cnt = -1;
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1; j <= 8; ++j)
        {
            ++cnt;
            if (mp[i][j])
                now |= temp << cnt;
        }
    }
    return now;
}
bool ok(int x, int y)
{
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}
bool ans;
void bfs(ull start, bool f)
{
    queue<node> q;
    q.push({start, 0});
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        if (!f)
        {
            if (mark[now.id])
                continue;
            mark[now.id] = 1;
        }
        else
        {
            if (mark[now.id])
            {
                ans = 1;
                return;
            }
        }
        if (now.step == 4)
            continue;
        int cnt = -1;
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                ++cnt;
                mp[i][j] = (int)(now.id >> cnt) & 1;
            }
        }
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                if (mp[i][j] && ok(i - 1, j) && mp[i - 1][j] == 1 && ok(i - 2, j) && mp[i - 2][j] == 0)
                {
                    mp[i - 2][j] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i - 2][j] = 0, mp[i][j] = 1;
                }
                if (mp[i][j] && ok(i + 1, j) && mp[i + 1][j] == 1 && ok(i + 2, j) && mp[i + 2][j] == 0)
                {
                    mp[i + 2][j] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i + 2][j] = 0, mp[i][j] = 1;
                }
                if (mp[i][j] && ok(i, j - 1) && mp[i][j - 1] == 1 && ok(i, j - 2) && mp[i][j - 2] == 0)
                {
                    mp[i][j - 2] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i][j - 2] = 0, mp[i][j] = 1;
                }
                if (mp[i][j] && ok(i, j + 1) && mp[i][j + 1] == 1 && ok(i, j + 2) && mp[i][j + 2] == 0)
                {
                    mp[i][j + 2] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i][j + 2] = 0, mp[i][j] = 1;
                }
                //--------------------------------------------------------------
                if (mp[i][j] == 1 && ok(i - 1, j) && mp[i - 1][j] == 0)
                {
                    mp[i - 1][j] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i - 1][j] = 0;
                    mp[i][j] = 1;
                }
                if (mp[i][j] == 1 && ok(i + 1, j) && mp[i + 1][j] == 0)
                {
                    mp[i + 1][j] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i + 1][j] = 0;
                    mp[i][j] = 1;
                }
                if (mp[i][j] == 1 && ok(i, j - 1) && mp[i][j - 1] == 0)
                {
                    mp[i][j - 1] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i][j - 1] = 0;
                    mp[i][j] = 1;
                }
                if (mp[i][j] == 1 && ok(i, j + 1) && mp[i][j + 1] == 0)
                {
                    mp[i][j + 1] = 1, mp[i][j] = 0;
                    q.push({get(), now.step + 1});
                    mp[i][j + 1] = 0;
                    mp[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    int x, y;
    while (~sc("%d%d", &x, &y))
    {
        ans = 0;
        mark.clear();
        mem(mp, 0);
        mp[x][y] = 1;
        for (int i = 2; i <= 4; ++i)
        {
            sc("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        bfs(get(), 0);
        mem(mp, 0);
        for (int i = 1; i <= 4; ++i)
        {
            sc("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        bfs(get(), 1);
        if (ans)
            pr("YES\n");
        else
            pr("NO\n");
    }
    return 0;
}