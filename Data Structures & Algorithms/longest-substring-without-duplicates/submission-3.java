class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int ans = 1;
        if (n == 0)
            return 0;
        int prev = -1;
        Map<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            System.out.println(ch);
            if (mp.containsKey(ch) && mp.get(ch) > prev) {
                prev = mp.get(ch);
            }
            mp.put(ch, i);
            ans = Math.max(ans, i - prev);
        }
        return ans;
    }
}
