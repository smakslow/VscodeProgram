#include<bits/stdc++.h>

using namespace std;
vector<int> v;
queue<int> q;
stack<int> s;
stack<string> str;
int main(){

    for(int i = 0;i < 10;i++){
        v.push_back(i * i);
        q.push(i);
        s.push(i);
    }
   
   for(int i = 0;i < 10;i++){
       cout << v[i] << " ";
   }
   cout << endl;

   while(!q.empty()){
       cout << q.front() << " ";
       q.pop();
   }
   cout << endl;

   while(!s.empty()){
       cout << s.top() <<" ";
       s.pop();
   }
   cout << endl;
   return 0;
}