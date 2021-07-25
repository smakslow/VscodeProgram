class A {
    class Solution {
        public int countTriples(int n) {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    int q = (int) Math.sqrt(i * i + j * j + 1.0);
                    if (q <= n && q * q == i * i + j * j)
                        ans++;
                }
            }
            return ans;
        }
    }
}
