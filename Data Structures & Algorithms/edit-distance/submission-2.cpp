class Solution {
public:
    int ans;
    int minDistance(string word1, string word2) {
        ans = INT_MAX;
        // solve(word1, word2, "",0,0,0);
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0] = i; 
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){ // Same characters
                    dp[i][j] = dp[i-1][j-1]; // no operation
                } else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                                        //replace    // delete      //insert
                }
            }
        }
        return dp[n][m];
        return ans;
    }

    void solve(string word1, string word2, string temp, int idx, int idx2, int cnt){
        if(temp.length() == word2.length()){
            cnt += word1.length() - idx;
            if(word2 == temp){
                ans = min(ans,cnt);
                return;
            } else return;
        }
        if(idx == word1.length()){
            cnt+= word2.length() - idx2;
            ans = min(ans,cnt);
        }
        if(idx > word1.length() || idx2 > word2.length()) return;

        int tempIdx = 0;
        while(tempIdx < temp.length()){
            if(temp[tempIdx] != word2[tempIdx]) return;
            tempIdx++;
        }

        if(word2[idx2] == word1[idx]){
            solve(word1, word2, temp + word1[idx], idx+1, idx2+1, cnt);
        } else{
            solve(word1, word2, temp, idx+1, idx2, cnt+1); // Delete
            solve(word1, word2, temp + word2[idx2], idx, idx2 + 1, cnt+1);
            solve(word1, word2, temp + word2[idx2], idx + 1, idx2 + 1, cnt+1);
        }
    }
};
