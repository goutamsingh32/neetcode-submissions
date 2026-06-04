class Solution {
public:

    vector<vector<int>> dp;
    string longestPalindrome(string s) {
        int n = s.length();
        dp = vector<vector<int>>(n,vector<int>(n,-1));

        solve(n,0,n-1,s);
        int ans = 0;
        int start = 0;int end = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans < dp[i][j]){
                    start = i;
                    end = j;
                    ans = dp[i][j];
                }
            }
        }
        return s.substr(start, end-start+1);
    }

    void solve(int n, int i, int j, string s){
        if(i > j) return;
        if(dp[i][j] != -1) return;

        if(isPalindrome(s,i,j)){
            dp[i][j] = j - i + 1;
            return;
        } else{
            dp[i][j] = 0;
        }
        solve(n,i+1,j,s);
        solve(n,i,j-1,s);
    }

    bool isPalindrome(string s, int i, int j){
        int n = s.length();
        while(i<j){
            if(s[i] != s[j]) return 0;
            i++;j--;
        }
        return true;
    }
};
