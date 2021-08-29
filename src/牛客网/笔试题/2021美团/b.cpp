#include <bits/stdc++.h>
using namespace std;

struct Seq
{
    int left, right;
    int sum;
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), index(n);
    for (int &num : nums)
        cin >> num;
    for (int &idx : index)
        cin >> idx;
    // 从后往前添加，使用哈希表维护区间左右端点+mulset维护区间和大小
    unordered_map<int, struct Seq> d; // [key, right], sum
    multiset<int> s;
    vector<int> ans(n, 0); 
    for (int i = n - 1; i >= 0; --i)
    {
        // 查询哈希表内是否含有端点进行合并区间
        index[i] -= 1;
        auto left = d.find(index[i] - 1), right = d.find(index[i] + 1);
        ans[i] = s.empty() ? 0 : *s.rbegin(); // 更新multiset最大值
        if (d.end() != left && d.end() != right)
        { // 将俩个区间合并为一个
            int ll = left->second.left, lr = left->second.right, lsum = left->second.sum;
            int rl = right->second.left, rr = right->second.right, rsum = right->second.sum;
            int sum = lsum + rsum + nums[index[i]];
            // 哈希表删除与新增
            d.erase(lr);
            d.erase(rl);
            d[ll] = d[rr] = {ll, rr, sum};
            // multiset删除与新增
            s.erase(lsum);
            s.erase(rsum);
            s.insert(sum);
        }
        else if (d.end() != left)
        { // 和左侧区间合并
            int ll = left->second.left, lr = left->second.right, lsum = left->second.sum;
            int sum = lsum + nums[index[i]];
            // 哈希表删除与新增
            d.erase(lr);
            d[ll] = d[index[i]] = {ll, index[i], sum};
            // multiset删除与新增
            s.erase(lsum);
            s.insert(sum);
        }
        else if (d.end() != right)
        {
            int rl = right->second.left, rr = right->second.right, rsum = right->second.sum;
            int sum = rsum + nums[index[i]];
            // 哈希表删除与新增
            d.erase(rl);
            d[index[i]] = d[rr] = {index[i], rr, sum};
            // multiset删除与新增
            s.erase(rsum);
            s.insert(sum);
        }
        else
        {
            d[index[i]] = {index[i], index[i], nums[index[i]]};
            s.insert(nums[index[i]]);
        }
    }
    for (int n : ans)
        cout << n << endl;
    return 0;
}
