#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char s[105];
    int x, y;
    scanf("%s%d%d", &s, &x, &y);
    int ans = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        ans = ans * x;
        if (s[i] >= '0' && s[i] <= '9')
            ans += (s[i] - '0');
        else
            ans += (s[i] - 'A') + 10;
    }
    char out[105];
    int cnt = 0;
    while (ans > 0)
    {
        int w = ans % y;
        if (w < 10)
            out[cnt++] = w + '0';
        else
            out[cnt++] = (w - 10) + 'A';
        ans /= y;
    }
    for (int i = cnt - 1; i >= 0; i--)
    {
        printf("%c", out[i]);
    }
    printf("\n");

    return 0;
}