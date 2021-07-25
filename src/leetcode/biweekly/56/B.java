import java.util.LinkedList;
import java.util.Queue;

class B {
    class Solution {
        int[] dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };

        public int nearestExit(char[][] maze, int[] entrance) {
            int x = entrance[0], y = entrance[1];
            int n = maze.length;
            int m = maze[0].length;

            boolean[][] vis = new boolean[n][m];
            Queue<int[]> q = new LinkedList<>();
            q.offer(new int[] { x, y, 0 });
            vis[x][y] = true;
            while (!q.isEmpty()) {
                int[] p = q.poll();

                for (int i = 0; i < 4; i++) {
                    int a = p[0] + dx[i];
                    int b = p[1] + dy[i];
                    if (a >= 0 && a < n && b >= 0 && b < m && maze[a][b] == '.' && !vis[a][b]) { //
                        q.offer(new int[] { a, b, p[2] + 1 });
                        vis[a][b] = true;
                    }
                    if ((a < 0 || a >= n || b < 0 || b >= m) && p[2] != 0) {
                        return p[2];
                    }
                }
            }
            return -1;
        }
    }
}