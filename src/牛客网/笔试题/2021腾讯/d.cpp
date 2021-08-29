#include<bits/stdc++.h>

using namespace std;
int func(int n) {
        n && (n += func(n-1));
        return n;
    }
int main(){
    cout << func(5) << endl;
    const char* str = "name hello";
printf("%d %d\n", sizeof(str), strlen(str));
    return 0;
}