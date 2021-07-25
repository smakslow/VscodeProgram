/* 求抛物线y^2 = 2Ax 与直线y = Bx + C 所围成的封闭图形面积.若图形不存在,则输出0 */
#include <bits/stdc++.h>
using namespace std;
const int nn = 5100;
const int inff = 0x3fffffff;
const double eps = 1e-8;
typedef long long LL;
const double pi = acos(-1.0);
const LL mod = 1000000007;
int compare(double x)
{
    if (abs(x) < eps)
        return 0;
    if (x > 0)
        return 1;
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        double a, b, c;
        a = B * B;
        b = 2 * B * C - 2 * A;
        c = C * C;
        double dt = b * b - 4 * a * c;
        if (compare(dt) <= 0)
            cout << 0 << endl;
        else
        {
            double x1 = (-b + sqrt(dt)) / (2 * a);
            double x2 = (-b - sqrt(dt)) / (2 * a);
            double y1 = B * x1 + C;
            double y2 = B * x2 + C;
            if (y1 < y2)
                swap(y1, y2);
            double ans = ((y1 * y1) / (2 * B) - (y2 * y2) / (2 * B)) - (C * y1 / B - C * y2 / B) - ((y1 * y1 * y1) / (6 * A) - (y2 * y2 * y2) / (6 * A));
            printf("%.6lf\n", ans);
        }
    }
    return 0;
}
