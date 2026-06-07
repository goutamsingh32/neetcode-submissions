class Solution {
    Map<Character, String> mp = new HashMap<>();
    public List<String> letterCombinations(String digits) {
        int n = digits.length();
        List<String> list = new ArrayList<>();
        if (n == 0)
            return list;
        mp = new HashMap<>();
        mp.put('2', "abc");
        mp.put('3', "def");
        mp.put('4', "ghi");
        mp.put('5', "jkl");
        mp.put('6', "mno");
        mp.put('7', "pqrs");
        mp.put('8', "tuv");
        mp.put('9', "wxyz");

        solve(digits, 0, list, "");
        return list;
    }
    public void solve(String digits, int idx, List<String> ans, String curr) {
        int n = digits.length();
        if (n == idx) {
            ans.add(curr);
            return;
        }
        String str = mp.get(digits.charAt(idx));

        for (int i = 0; i < str.length(); i++) {
            solve(digits, idx + 1, ans, curr + str.charAt(i));
        }
    }
}
