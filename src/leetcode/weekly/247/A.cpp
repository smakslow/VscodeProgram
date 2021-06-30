#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int maxProductDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};

int main()
{
    Solution s;
    vector<int> v;
    for (int i = 1; i <= 10; i++)
        v.push_back(i);
    cout << s.maxProductDifference(v) << endl;
    return 0;
}