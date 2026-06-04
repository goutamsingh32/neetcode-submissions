class Solution {
public:
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(amt+1, vector<int>(n,-1));
        return solve(0, amt, dp, coins);
    }

    int solve(int idx, int amt, vector<vector<int>> &dp, vector<int> coins){
        int n = coins.size();
        if(amt == 0) return 1;
        if(idx >= n) return 0;

        if(dp[amt][idx] != -1) return dp[amt][idx];

        int notPick = solve(idx + 1, amt, dp, coins);
        int pick = 0;
        if(amt - coins[idx] >= 0){
            pick = solve(idx, amt - coins[idx], dp, coins);
        }
        return dp[amt][idx] = pick + notPick;
    }
};
