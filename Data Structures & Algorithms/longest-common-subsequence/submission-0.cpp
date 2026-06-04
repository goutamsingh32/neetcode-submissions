class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        dp = vector<vector<int>>(n,vector<int>(m,-1));

        solve(text1, text2,0,0);
        return dp[0][0];
    }
    
    int solve(string s1, string s2, int i, int j){
        int n = s1.length();
        int m = s2.length();
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        } 
        if(s1[i] == s2[j]){
            dp[i][j] = solve(s1,s2,i+1,j+1) + 1;
        } else{
            dp[i][j] = max(
            solve(s1,s2,i,j+1),
            solve(s1,s2,i+1,j));
        }
        return dp[i][j];
    }
};
