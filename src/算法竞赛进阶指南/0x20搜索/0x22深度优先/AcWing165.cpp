#include<iostream>
#include<algorithm>
using namespace std;
const int N = 20;
int c[N],cab[N];//小猫重量，记录已租用缆车cnt辆缆车的当前重量
int n,w,ans; //n只小猫，重量之和不超过w，最少需要花费

void dfs(int now ,int cnt){ //处理第now只小猫的分配过程，目前已租用cnt辆缆车
    if(cnt >= ans) return;
    if(now = n + 1){ //当前已经是最后一只小猫结束，更新最小值
        ans = min(ans,cnt);
        return;
    }
    for(int i = 1;i <= cnt;i++){ //分配到已租用缆车
        if(cab[i] + c[now] <= w){ //如果该缆车能装下小猫
            cab[i] += c[now];//更新
            dfs(now + 1,cnt);
            cab[i] -= c[now];//还原现场
        }
    }
    cab[cnt + 1] = c[now]; //已租用缆车装不下，增加缆车数量，将小猫装入该缆车
    dfs(now + 1,cnt + 1);
    cab[cnt + 1] = 0;
}

int main(){
    cin >> n >> w;
    ans = n;
    for(int i = 1;i <= n;i++) cin >> c[i];
    sort(c + 1, c + n + 1);
    reverse(c + 1,c + n + 1);//优先搜索重量较大的小猫
    dfs(1,0);
    cout << ans << endl;
    return 0;
}