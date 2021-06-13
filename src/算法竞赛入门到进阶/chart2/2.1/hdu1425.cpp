#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000001];
int n , m;
int main(){
     while(~(scanf("%d%d",&n,&m))){
         for(int i = 0;i < n;i++){
             scanf("%d",&a[i]);
         }
         sort(a,a + n ,greater<int>());
         for(int i = 0;i < m;i++){
             if(i == m-1) printf("%d\n",a[i]);
             else printf("%d ",a[i]);
         }

        // sort(a, a + n);
        // for(int i = n - 1; i >= n - m;i--){
        //     if(i == n-m) printf("%d\n",a[i]);
        //     else printf("%d ",a[i]);
        // }
     }
    return 0;
}