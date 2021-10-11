#include<bits/stdc++.h>
using namespace std;
char room[23][23];
int dir[4][2] = {
    {-1,0},
    {0, -1},
    {1, 0},
    {0, 1}
};
struct node
{
    int x,y;
};
int row,col,num;
#define check(x,y) (x < row && x >= 0  && y < col && y >= 0)
void BFS(int dx,int dy){
    num = 1;
    queue<node> q;
    node start , next;
    start.x = dx;
    start.y = dy;
    q.push(start);
    while (!q.empty())
    {
        start = q.front();
        q.pop();
        for (int  i = 0; i < 4; i++)
        {
            next.x = start.x + dir[i][0];
            next.y = start.y + dir[i][1];
            if(check(next.x,next.y) && room[next.x][next.y] == '.'){
                room[next.x][next.y] = '#';
                num ++;
                q.push(next);
            }
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    int x,y,dx,dy;
    while(cin >> row >> col,row && col){
        for(y = 0;y < col;y++){
            for(x = 0; x < row;x++){
                cin >> room[x][y];
                if(room[x][y] == '@'){  //起点
                    dx = x;
                    dy = y;
                }
            }
        }
        num = 0;
        BFS(dx,dy);
        cout << num << endl;
    }
    return 0;
}