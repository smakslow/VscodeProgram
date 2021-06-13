#include<bits/stdc++.h>

using namespace std;

char mpt[10][10];
int main(){
    for (int i = 0; i <= 4; i++)
    {
        scanf("%s",mpt[i] + 1);

    }
    for(int i = 1;i <= 4;i++){
        for(int j = 1;j <= 4;j++){
            printf("%c",mpt[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}