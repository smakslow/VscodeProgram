#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll k;
ll dfs(int n,ll k){
    if(k == 1ll << n -1) return n;
    if(k < 1ll << n - 1) return dfs(n - 1,k);
    return dfs(n - 1, k - (1ll << n - 1));
}
int main()
{
    cin >> n >> k;
    cout << dfs(n,k) <<endl;
    return 0;
}