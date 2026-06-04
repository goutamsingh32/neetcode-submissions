class Solution {
public:
    vector<int>dp;
    int numDecodings(string s) {
        int n = s.length();
        dp = vector<int>(n,-1);
        return solve(s,0);

    }

    int solve(string s, int i){
        if(i >= s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        if(s[i] > '2'){
            dp[i] =  solve(s,i+1);
        }else if(s[i] == '1'){
            if(i+1 < s.length()){
                dp[i] =  solve(s,i+2) + solve(s,i+1);
            } else{
                dp[i] = solve(s,i+1);
            }
        }else if(s[i] =='2'){
            if(i+1 < s.length() && s[i+1] <= '6'){
                dp[i] = solve(s,i+2) + solve(s,i+1);
            } else{
                dp[i] = solve(s,i+1);
            }
        }
        return dp[i];
    }
    
};
