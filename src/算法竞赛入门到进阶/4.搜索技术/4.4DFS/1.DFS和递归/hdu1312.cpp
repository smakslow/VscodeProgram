#include<bits/stdc++.h>

using namespace std;
int row,col;
#define CHECK(x,y) (x >=0 && x < row && y >=0 && y < col)
char room[23][23];
int num = 0;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};   
void DFS(int x,int y){
    room[x][y] = '#';
    num++;
    for(int i = 0;i < 4;i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(CHECK(newx,newy) && room[newx][newy] == '.'){
            DFS(newx,newy);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    int x,y,startX,startY;
    while(cin >> row >> col,row && col){
        for(y = 0;y < col;y++){
            for(x = 0; x < row;x++){
                cin >> room[x][y];
                if(room[x][y] == '@'){  //起点
                    startX = x;
                    startY = y;
                }
            }
        }
        num = 0;
        DFS(startX,startY);
        cout << num << endl;
    }
    return 0;
    return 0;
}