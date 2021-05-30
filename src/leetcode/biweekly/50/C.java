package leetcode.biweeklyrace._50;


public class C {
    class Solution {
        public int[] getMaximumXor(int[] nums, int maximumBit) {
            int n = nums.length;
            nums[0] ^= (1 << maximumBit) - 1;
            for (int i = 0; i < n - 1; i++) {
                nums[i + 1] ^= nums[i];
            }
            for (int i = 0; i < nums.length / 2; i++) {
                int temp = nums[i];
                nums[i] = nums[nums.length - 1 - i];
                nums[nums.length - 1 - i] = temp;
            }
            return nums;
        }
    }
}
