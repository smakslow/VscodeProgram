#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool my_less(int i,int j) {
    return i < j;  //自定义小于
}

bool my_greator(int i ,int j){
    return i > j;  //自定义大于
}

struct Student{
    char name[256];
    int score;
};
bool compare(struct Student *a, struct Student *b){
    return a->score > b->score; //分数从大到小排列
}
int main(){
    vector<int > a = {1,2,3,5,6,2,7,1,0};
    //sort(a.begin(),a.end()); //0 1 1 2 2 3 5 6 7 
    //sort(a.begin(),a.end(),my_less); //0 1 1 2 2 3 5 6 7 
    // sort(a.begin(),a.end(),my_greator); //7 6 5 3 2 2 1 1 0
     //sort(a.begin(),a.end(),less<int>()); //0 1 1 2 2 3 5 6 7
    sort(a.begin(),a.end(),greater<int>()); //7 6 5 3 2 2 1 1 0 
    for(int i = 0;i < a.size();i++){
        cout << a[i] << " ";
    }

    vector<struct Student *> list;
    //list.push_back();
    sort(list.begin(),list.end(),compare);
    for(auto x : list){
        cout << x->name << " "<< x->score <<endl;
    }
    return 0;
}