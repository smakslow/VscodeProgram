#include<bits/stdc++.h>
using namespace std;

#define Swap(x, y){int t = x; x = y; y = t;}


//打印n个数的全排列
const int N = 1001;
int a[N];

//递归求解全排列
int num = 0; //统计全排列的个数
void Perm(int begin,int end){
    int i;
    if(begin == end) num++;
    else
        for(int i = begin;i <= end;i++){
            Swap(a[begin],a[i]);
            Perm(begin+ 1,end);
            Swap(a[begin],a[i]);
        }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    // do{
    //     for(int i = 1;i <= n;i++) cout << a[i];
    //     cout << endl;
    // }while(next_permutation(a + 1,a + n + 1));

    Perm(1,n);
    cout << endl << num;

    return 0;
}