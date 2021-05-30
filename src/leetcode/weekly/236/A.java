package leetcode.weeklyrace._236;

public class A {
    class Solution {
        public int arraySign(int[] nums) {
            int left = 0;
            int right = 0;
            int ans = 0;
            for (int num : nums) {
                if (num > 0) left++;
                else if (num < 0) right++;
                else {
                    return ans;
                }
            }
            if (right % 2 == 0) return 1;
            return -1;
        }
    }
}
