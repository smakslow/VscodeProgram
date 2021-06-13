#include<iostream>
using namespace std;
const int N = 100001;

int f[N];

void init(){
    for(int i = 0;i < N;i++) f[i] = i;
}

int find(int x){
    return x == f[x] ? x : find(f[x]);
}

void join(int x,int y){
    x = find(x);
    y = find(y);
    if(x != y) f[x] = y;
}
int main(){


    return 0;
}