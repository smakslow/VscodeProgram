import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;


public class Main{
    static PrintWriter out = new PrintWriter(System.out);
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        HashMap<String,HashSet<String>> map = new HashMap<>();
        String a,b;
        while(n-- > 0){
            a  = next();
            b = next();
            if(map.containsKey(a)){
                if(map.get(a).contains(b)){
                    out.println("YES");
                }else{
                   HashSet<String>  s=  map.get(a);
                    s.add(b);
                    map.put(a,s);
                    out.println("NO");
                }
            }else{
                HashSet<String> s= new HashSet<>();
                s.add(b);
                map.put(a,s);
                out.println("NO");
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
