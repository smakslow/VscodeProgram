
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
public class b {
    static PrintWriter out = new PrintWriter(System.out);
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");
    public static void main(String[] args) throws IOException{
        int n = nextInt();
        int k = nextInt();
        int[][] person = new int[n][2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            person[i][0] = nextInt();
            map.put(person[i][0], i);
        }
        for (int i = 0; i < n; i++) {
            person[i][1] = nextInt();
        }
        Arrays.sort(person, (o1, o2) -> (o1[0] - o2[0]));
        int[] ans = new int[n];
        Queue<Integer> q = new PriorityQueue<>();
        int sum = 0;
        for (int i = 0; i < person.length; i++) {
            ans[map.get(person[i][0])] = sum + person[i][1];
            if (q.size() < k) {
                q.offer(person[i][1]);
                sum = sum + person[i][1];
            } else {
                if (q.peek() < person[i][1]) {
                    sum = sum - q.poll();
                    sum = sum + person[i][1];
                    q.offer(person[i][1]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                out.print(ans[i] + " ");
            } else {
                out.print(ans[i]);
            }
        }
        out.flush();
        out.close();
    }
    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}
