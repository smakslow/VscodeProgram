#include<iostream>
using namespace std;
void print_subset(int n,int k){
    for(int i = 0;i < (1 << n);i++){
        int num = 0,kk = i;
        while (kk)
        {
            kk = kk & (kk - 1); // 消除kk的二进制数的最后一个1
            num++;//统计1的个数
        }
        if(num == k){
            for(int j = 0;j < n;j++){
                if(i & (1 << j)) cout << j << " ";
            }
            cout << endl;
        }
        
    }
}
int main(){
    int n,k;
    cin >> n >> k;
    print_subset(n,k);
    return 0;
}