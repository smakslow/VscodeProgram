#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    int ans = 1e9;
    sort(nums2.begin(),nums2.end());
    do{
        int t = 0;
        for(int i = 0; i < nums1.size();i++){
            t += (nums1[i]^nums2[i]);
        }
        ans = min(ans,t);
    }while(next_permutation(nums2.begin(),nums2.end()));
return ans;

}
 int main() {

cout << (0^2877579) << endl;
     cout << 3  +2 << endl;
     return 0;
 }