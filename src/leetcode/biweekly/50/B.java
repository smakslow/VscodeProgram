package leetcode.biweeklyrace._50;

public class B {
    class Solution {
        public int[] countPoints(int[][] points, int[][] queries) {
            int[] ans = new int[queries.length];
            for (int i = 0; i < queries.length; i++) {
                int x = queries[i][0];
                int y = queries[i][1];
                int r = queries[i][2];
                for (int[] point:  points) {
                    int x1 = point[0];
                    int y1 = point[1];

                    if(!((x - x1)*(x - x1) + (y - y1)*(y - y1) > r*r)) ans[i]++;
                }
            }
            return ans;
        }
    }
}
