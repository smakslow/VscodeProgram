class C{
    class Solution {
        int N = 100010;
        public long wonderfulSubstrings(String word) {
             Map<Integer,Integer> map = new HashMap<>();
             int last = 0;
             map.put(0,1);
             long ans = 0;
             char[] chars = word.toCharArray();
             int n = chars.length;
             for (int i = 0; i < n; i++){
                 int c = chars[i] - 'a';
                 last = last ^ (1 << c);
                 ans += map.getOrDefault(last,0);
                for (int v = 0; v < 10; v++){
                    ans += map.getOrDefault(last ^ (1 << v),0);
                }
                map.put(last,map.getOrDefault(last,0 )  + 1);
             }
             return ans;
        }
    }
}