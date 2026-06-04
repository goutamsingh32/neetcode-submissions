class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1)
            return cost[0];
        if(n==2){
            return min(cost[1], cost[0]);
        }

        int step1 = 0;
        int step2 = 0;

        for (int i = 2; i <= n; i++) {
            int temp = step2;
            step2 = min(step1 + cost[i-2], step2 + cost[i-1]);
            step1 = temp;
        }
        return step2;
    }
};