public class B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int start = 0;
        StringBuilder ans0 = new StringBuilder();
        StringBuilder ans1 = new StringBuilder();

        for (int i = 1; i < s.length(); i++) {
            char c = s.charAt(i);
            if ((c >= 'A' && c <= 'Z') || c == '-' || c == '_') {
                ans0.append(Character.toUpperCase(s.charAt(start))).append(s, start + 1, i);
                ans1.append(Character.toLowerCase(s.charAt(start))).append(s, start + 1, i).append('_');
                start = i;
                if (c == '-' || c == '_')
                    start++;
            }
        }
        String s1 = ans0.append(Character.toUpperCase(s.charAt(start))).append(s, start + 1, s.length()).toString();
        String s2 = ans1.append(Character.toLowerCase(s.charAt(start))).append(s, start + 1, s.length()).toString();

        System.out.print(s1 + " ");
        System.out.print(s1.substring(0, 1).toLowerCase() + s1.substring(1) + " ");
        System.out.print(s2+" ");
        System.out.println(s2.replaceAll("_", "-"));

    }
}
