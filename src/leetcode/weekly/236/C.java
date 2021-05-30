package leetcode.weeklyrace._236;

public class C {
    class Solution {
        public int minSideJumps(int[] obstacles) {
            int n = obstacles.length - 1;
            int[][] dp = new int[n + 1][3];

            dp[0][0] = dp[0][2] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < 3; j++) {
                    dp[i][j] = (int) 1e9;
                    if (obstacles[i] == j + 1) continue;
                    for (int k = 0; k < 3; k++) {
                        if (obstacles[i] == k + 1) continue;
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + (k == j ? 0 : 1));
                    }
                }
            }
            return Math.min(dp[n][0], Math.min(dp[n][1], dp[n][2]));
        }
    }
}
