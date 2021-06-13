#include<iostream>
#include<algorithm>

using namespace std;
const int N = 100010;
int n,k;
int w[N];
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 0;i < n;i++){
            cin >> w[i];
        }
        int ans = n;
        for(int i = 1; i<= 100;i++){
            int t = 0;
            for(int j = 0; j < n;j++){
                if(w[j] != i){
                    t++;
                    j += k - 1;
                }
            }
            ans = min (ans , t);
        }
        cout << ans << endl;
    }
    return 0;
}