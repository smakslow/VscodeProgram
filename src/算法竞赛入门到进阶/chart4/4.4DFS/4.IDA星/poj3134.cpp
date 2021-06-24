#include<iostream>
using namespace std;

int val[1010];
int pos, n;
bool ida(int now ,int depth){
    if(now > depth) return false;
    if(val[pos] << (depth - now) < n) return false;
    if(val[pos] == n) return false;
    pos++;
    for(int i = 0;i < pos;i++){
        val[pos] = val[pos - 1] + val[i];
        if(ida(now + 1,depth)) return true;
        val[pos] = abs(val[pos- 1] - val[i]);
        if(ida(now +1,depth)) return true;
    }
    pos--;
    return false;
}

int main(){
    while (cin >>n && n)
    {
        /* code */
        int depth;
        for(depth = 0;;depth++){
            val[pos = 0] = 1;
            if(ida(0,depth))break;
        }
        cout << depth << endl;
    }
   
    return 0;
}