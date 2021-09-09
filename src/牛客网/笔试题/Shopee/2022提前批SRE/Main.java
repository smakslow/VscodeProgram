public class Main {
    public String char_and_num_return(String text_source) {
        // write code here
        String[] str = text_source.split(" ");
        StringBuilder sb = new StringBuilder();
        ArrayList<String> list = new ArrayList<>();
        for (String s : str) {
            if (Character.isDigit(s.charAt(0))) {
                list.add(s);
            } else {
                sb.append(s).append(' ');
            }
        }
        list.sort((o1, o2) -> {
            if (o1.length() == o2.length()) return o1.compareTo(o2);
            return o1.length() - o2.length();
        });
        for (String s : list) {
            sb.append(s).append(' ');
        }
        return sb.substring(0, sb.length() - 1);
    }
    public String Paired69 (String S) {
        // write code here
    }
    
    public int cost (int[] array) {
        // write code here
    }
}
