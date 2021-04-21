#include<iostream>

using namespace std;
int a,n;
int main(){
   cin >> a >> n;
   int ans  = 0;
   for(int i = n;i >= 1;i--){
       ans += i * a;
       a *= 10;
      
   }
   cout << ans << endl;
   return 0;
}