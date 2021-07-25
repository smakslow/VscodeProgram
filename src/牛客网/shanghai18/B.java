import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class B {
    static PrintWriter out = new PrintWriter(System.out);
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");

    static class Record {
        String date;
        String id;
        double temper;

        public Record(String date, String id, double temper) {
            this.date = date;
            this.id = id;
            this.temper = temper;
        }
    }

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int cnt = 0;
        Record[] records = new Record[n];
        for (int i = 0; i < n; i++) {
            String date = next();
            String id = next();
            double temper = nextDouble();
            if (temper >= 38.0)
                cnt++;
            records[i] = new Record(date, id, temper);
        }
        Arrays.sort(records, new Comparator<Record>() {
            @Override
            public int compare(Record o1, Record o2) {
                if (o1.date.equals(o2.date)) {
                    if (o1.temper == o2.temper) {
                        return o1.id.compareTo(o2.id);
                    }
                    return Double.compare(o2.temper, o1.temper);
                }
                return o2.date.compareTo(o1.date);
            }
        });
        StringBuilder sb = new StringBuilder();
        sb.append(cnt).append("\n");
        for (int i = 0; i < n; i++) {
            if (records[i].temper >= 38.0)
                sb.append(records[i].date).append(' ').append(records[i].id).append(' ').append(records[i].temper)
                        .append("\n");
        }
        out.print(sb);
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
