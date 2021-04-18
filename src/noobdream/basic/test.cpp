#include<bits/stdc++.h>

using namespace std;
int f[105]={0};
int main(){
    int n,x;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        f[x]++;
    }
    
    for (int i = 0; i <= 100; i++)
    {
        if(f[i] > 0)printf("%d %d\n",i,f[i]);
    }
    
    return 0;
}