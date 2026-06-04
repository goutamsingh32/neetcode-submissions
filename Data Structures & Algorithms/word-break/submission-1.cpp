class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<string, int> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        if (!n)
            return 1;
        for (string str : wordDict) {
            mp[str] = 1;
        }
        dp = vector<vector<int>>(n + 1,
                                 vector<int>(n + 1, -1)); // start, len
                                                          // -1 -> not-visited
                                                          // 1 -> true;
                                                          // 0 -> false;

        return isWordBreak(s, 0);
    }

    bool isWordBreak(string s, int start) {
        int n = s.length();
        if (start >= n)
            return true;
        for (int i = 1; i <= n - start; i++) {
            if (dp[start][i] == -1) {
                string temp = s.substr(start, i);
                if (mp.find(temp) != mp.end()) {
                    if (isWordBreak(s, start + i)) {
                        dp[start][i] = 1;
                        return true;
                    } else {
                        dp[start][i] = 0;
                    }
                }
            } else if (dp[start][i] == 1) {
                return true;
            } else
                return false;
        }
        return false;
    }
};
