#include <bits/stdc++.h>

using namespace std;
int main()
{
    double a;
    scanf("%lf", &a);
    if (a < 1000)
        printf("discount=1,pay = %g \n", a);
    else if (a >= 1000 && a < 2000)
        printf("discount=0.95,pay=%g\n", a * 0.95);
    else if (a >= 2000 && a < 3000)
        printf("discount=0.9,pay=%g\n", a * 0.9);
    else if (a >= 3000 && a < 5000)
        printf("discount=0.85,pay=%g\n", a * 0.85);
    else if (a >= 5000)
        printf("discount=0.8,pay=%g\n", a * 0.8);

    return 0;
}