#include<bits/stdc++.h>

using namespace std;

int main(){
    //priority_queue <int,vector<int>,greater<int> > q; //小根堆，默认是大根堆
    priority_queue <int> q;//大根堆
    for(int i = 1;i < 100;i++){
        q.push(i);
    }
    for(int i = 1;i < 100;i++){
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}