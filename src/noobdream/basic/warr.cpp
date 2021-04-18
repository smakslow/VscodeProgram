#include<bits/stdc++.h>

using namespace std;

int f[105] = {0};
int p[105] = {0};
int main(){
  int n,x;
  scanf("%d",&n);
  for(int i = 1;i <= n;i++){
      scanf("%d",&x);
      f[x]++;
  }
for(int i = 1;i <= 100;i++) p[f[i]] = i;
for(int i = 1; i <= 100;i++){
    if(p[i] > 0){
        printf("%d %d \n",p[i],i);
    }
}

  return 0;
}