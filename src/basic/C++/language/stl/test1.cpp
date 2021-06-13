#include<bits/stdc++.h>

using namespace std;
int finx(vector<int> &arr){
    unordered_map<int , int > map;
    for(int i = 0;i < arr.size();i++){
        if(map.count(arr[i])){
            map[arr[i]]++;
        }else{
            map[arr[i]] = 1;
        }
    }
    int x = 0;
    for(auto&& e : map){
        if(e.first == e.second){
            x = max(e.first,x);
        }
    }
    return x;
}
int main(){

}