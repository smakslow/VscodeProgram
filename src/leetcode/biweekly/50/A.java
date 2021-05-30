package leetcode.biweeklyrace._50;

public class A {
    class Solution {
        public int minOperations(int[] nums) {
            int cnt = 0;
            if (nums.length < 2) return cnt;
            for (int i = 1; i < nums.length; i++) {
                if (nums[i] <= nums[i - 1]) {
                    int t = nums[i - 1] - nums[i] + 1;
                    cnt += t;
                    nums[i] += t;
                }
            }
            return cnt;
        
        }
    }
}
