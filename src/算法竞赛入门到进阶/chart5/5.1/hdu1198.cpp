#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N = 60*60 + 1;
int type[12][4]={{1,1,0,0},{0,1,1,0},{1,0,0,1},{0,0,1,1},
                {0,1,0,1},{1,0,1,0},{1,1,1,0},{1,1,0,1},
                {1,0,1,1},{0,1,1,1},{1,1,1,1},{0,0,0,0}};
int f[N];
int find(int x){
    return x == f[x] ? x : find(f[x]);
}

void join(int x,int y){
    x = find(x);
    y = find(y);
    if(x != y) f[x] = y;
}
int count(int n){
    int t[N];
    for(int i = 1;i <= n;i++) t[i] = find(i);
    sort(t + 1, t + n + 1);
    return unique( t + 1, t + n + 1) - (t + 1);
}
int n,m;
char c[60][60];

int main(){
    while(~scanf("%d%d",&m,&n), !(m == -1 && n == -1)){
        for(int i = 0;i <= N;i++) f[i] = i;
        for(int i = 1;i <= m;i++){
            for(int j = 1; j <= n;j++){
                scanf(" %c",&c[i][j]);
            }
        }
        for(int i=0;i<=n+1;i++)
            c[0][i] = c[m+1][i] ='A'+11;
        for(int i=0;i<=m+1;i++)
            c[i][0] = c[i][n+1] ='A'+11;

           for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(type[c[i][j]-'A'][3]==1&&type[c[i+1][j]-'A'][1]==1)
                        {if(find((i-1)*n+j)!=find((i)*n+j))
                        join((i-1)*n+j,(i)*n+j);//cout<<"yes下"<<i<<' '<<j<<endl;
                        }
                if(type[c[i][j]-'A'][2]==1&&type[c[i][j+1]-'A'][0]==1)
                        {if(find((i-1)*n+j)!=find((i-1)*n+j+1))
                        join((i-1)*n+j,(i-1)*n+j+1);//cout<<"yes右"<<i<<' '<<j<<endl;
                        }
                if(type[c[i][j]-'A'][1]==1&&type[c[i-1][j]-'A'][3]==1)
                        {if(find((i-1)*n+j)!=find((i-2)*n+j))
                        join((i-1)*n+j,(i-2)*n+j);//cout<<"yes上"<<i<<' '<<j<<endl;
                        }
                if(type[c[i][j]-'A'][0]==1&&type[c[i][j-1]-'A'][2]==1)
                        {if(find((i-1)*n+j)!=find((i-1)*n+j-1))
                        join((i-1)*n+j,(i-1)*n+j-1);//cout<<"yes左"<<i<<' '<<j<<endl;
                        }
            }
        int s=count(n*m);
    }
    return 0;
}