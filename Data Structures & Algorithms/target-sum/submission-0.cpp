class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i: nums){
            total += i;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, INT_MIN));
        return solve(nums, dp,0,target, 0,total);
          
    }
    int solve(vector<int> nums, vector<vector<int>> &dp, int sum, int target, int idx, int total){
        if(idx == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }

        if(dp[idx][total + sum] != INT_MIN) return dp[idx][total + sum];

        dp[idx][total + sum] = solve(nums, dp, sum + nums[idx], target, idx + 1, total)
                                + solve(nums,dp, sum - nums[idx], target, idx + 1, total);
        return dp[idx][total + sum];
    }
};
