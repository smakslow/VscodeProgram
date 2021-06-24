#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int main()
{
    cin >> n >> s;
    int a = 0, b = 0;
    for(auto c : s){
        if(c == 'A') a++;
        else b++;
    }
    if(a > b) cout << "A";
    else if( a < b) cout << "B";
    else cout << "T";
    cout << endl;
    return 0;
}