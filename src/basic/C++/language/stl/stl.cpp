#include<bits/stdc++.h>

using namespace std;

int cmp(int a,int b){
    return a > b;
}
int f[107] = {0};
int main(){
      int n;
      scanf("%d",&n);
      for(int i = 0;i < n;i++){
          scanf("%d",&f[i]);
      }

      sort(f,f + n);

      for(int i = 0;i < n;i++){
          printf("%d ",f[i]);
      }
      //在从小到大的数列中
      int a = lower_bound(f,f + n,2) - f; //查找第一个大于等于2的元素的索引
      int b = upper_bound(f, f + n,3) - f; //查找第一个大于3 的元素的索引

      printf("\n%d %d \n",a,b);
      printf("%d %d",f[a],f[b]);

      //在从大到小的数列中
      //sort(f, f + n, cmp);
      sort(f, f + n, greater<int>());
      for(int i = 0;i < n;i++){
          printf("%d ",f[i]);
      }
      int c = lower_bound(f, f + n, 3 ,greater<int>()) - f; //查找第一个小于等于3的元素的索引
      int d = upper_bound(f, f + n, 2 ,greater<int>()) - f; //查找第一个小于2的元素的索引
      
      

      printf("\n%d %d \n",c,d);
      printf("%d %d",f[c],f[d]);
      return 0;
}

