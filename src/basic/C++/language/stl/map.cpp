#include<bits/stdc++.h>

using  namespace std;

int main(){
    int n,q,x;
    map<int ,int > m;
    cin >> n;
    for(int i = 0;i < n;i++){
         cin >> x;
         m[x]++;
    }
    cin >> q;
    for(int i = 0;i < q;i++){
        cin >> x;
        if(m[x] == 0){
            m[x]++;
            cout << "no" << endl;
        }else{

            cout << "find" << endl;
        }
    }
    return 0;
}