class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0); // Number of ways to climb on each index
        if(n==1) return 1;
        dp[1] = 1;
        dp[2] = 2;
        int current = 2;
        int prev = 1;
        for(int i=3;i<=n;i++){
            int temp = current;
            current = current + prev;
            prev = temp;
        }
        return current;
    }
};
