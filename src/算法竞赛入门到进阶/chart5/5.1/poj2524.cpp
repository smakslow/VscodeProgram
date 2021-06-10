#include<iostream>

using namespace std;
const int maxn = 50001;

int s[maxn];

void init(){
    for(int i = 1;i < maxn;i++){
        s[i] = i;
    }
}

int find(int x){
    return x == s[x] ? x : find(s[x]);
}

void union_set(int x,int y){
    x = find(x);
    y = find(y);
    if(x != y) s[x] = s[y];
}

int n,m;

int main(){
    ios::sync_with_stdio(false);
    int id= 1;
    while (1)
    {
    cin >> n >> m;
    if(n == 0 && m == 0) break;
    init();
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        union_set(x,y);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == i) ans++;
    }
    cout << "Case "<< id <<": "<< ans << endl;
    id++;
    }
    return 0;
}