class C {
    class Solution {
        public int colorTheGrid(int m, int n) {
            int mod = 1000000007;
            int[][] dp = new int[m + 1][n + 1];
            dp[1][1] = 3;
            for(int i = 2 ;i <= m;i++){
                dp[i][1] = d[i - 1][1]
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {

                }
            }
            return dp[m][n];
        }
    }

    class Solution {
        static final int MOD = 1000000007;
    
        public int numOfWays(int n,int m) {
            long fi0 = 6, fi1 = 6;
            for (int i = 2; i <= n; ++i) {
                long newFi0 = (2 * fi0 + 2 * fi1) % MOD;
                long newFi1 = (2 * fi0 + 3 * fi1) % MOD;
                fi0 = newFi0;
                fi1 = newFi1;
            }
            return (int) ((fi0 + fi1) % MOD);
        }
    }
    
    
}