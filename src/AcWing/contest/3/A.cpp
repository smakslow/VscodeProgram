#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int T,n,m,r,c;
    cin >> T;
    while(T--){
        cin >> n >> m >>r >> c;
        int ans = 0;
        ans = max(max(r - 1, n - r) + max(c - 1,m - c),ans);
        cout << ans << endl;
    }
    return 0;
}