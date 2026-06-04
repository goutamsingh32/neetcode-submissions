class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        if(n==1) return 0;
        if(n==2) return max(0, prices[1]-prices[0]);
        vector<int> buy(n,0);
        vector<int> sell(n,0);

        buy[0] = -prices[0];
        sell[1] = max(0, buy[0] + prices[1]);
        buy[1] = -min(prices[0],prices[1]);

        for(int i=2;i<n;i++){
            buy[i] = max(buy[i-1],sell[i-2] - prices[i]);
            sell[i] = max(sell[i-1], prices[i] + buy[i-1]);
        }    
        return sell[n-1];
    }
};
