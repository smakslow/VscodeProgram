class B{
    class Solution {
        public int[][] rotateGrid(int[][] grid, int k) {
            int n = grid.length;
            int m = grid[0].length;
            int[][] ans = new int[n][m];
            List<int[]> t;
            for (int a = n, b = m, i = 0; a > 0 && b > 0; a -= 2, b -= 2, i++) {
                int x = i, y = i;
                t = new ArrayList<>();
                for (int j = 0; j < b - 1; j++) t.add(new int[]{x, ++y});

                for (int j = 0; j < a - 1; j++) t.add(new int[]{++x, y});

                for (int j = 0; j < b - 1; j++) t.add(new int[]{x, --y});

                for (int j = 0; j < a - 1; j++) t.add(new int[]{--x, y});

                for (int j = 0; j < t.size(); j++) {
                    int z = (j + k) % t.size();
                    ans[t.get(j)[0]][t.get(j)[1]] = grid[t.get(z)[0]][t.get(z)[1]];
                }

            }
            return ans;
        }

    }
}