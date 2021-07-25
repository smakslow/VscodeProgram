class B {
    class Solution {
        public int countPalindromicSubsequence(String s) {
            int ans = 0;
            char[] chars = s.toCharArray();
            int n = chars.length;
            for (char c = 'a'; c <= 'z'; c++) {
                int i = 0;
                while (i < n) {
                    if (chars[i] == c)
                        break;
                    else
                        i++;
                }
                int j = n - 1;
                while (j >= 0) {
                    if (chars[j] == c)
                        break;
                    else
                        j--;
                }
                if (j - i <= 1)
                    continue;
                HashSet<Character> set = new HashSet<>();
                for (int k = i + 1; k < j; k++) {
                    set.add(chars[k]);
                }
                ans += set.size();
            }
            return ans;

        }
    }
}