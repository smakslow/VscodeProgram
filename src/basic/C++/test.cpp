#include <iostream>
 
using namespace std;
const int nmax=100000+5;
int a[nmax];
int dp[nmax];
 
int main(int argc, char** argv) {
	int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>a[i];		
    }
    int ans=-1;
    int tmp;
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        dp[i]=a[i];
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
    }
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
	return 0;
}