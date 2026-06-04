class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        if(n==3) return max(nums[0], max(nums[1],nums[2]));

        vector<int>dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Include first index
        for(int i=2;i<n-1;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int res1 = dp[n-2];
        
        //Excldude first index so that we can include last one
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        //  0 1 2 3
        for(int i=3;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        } 
        int res2 = dp[n-1];
        return max(res1, res2);
    
    }
};
