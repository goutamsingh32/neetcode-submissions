class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        if(n==1) return 0;
        if(n==2) return max(0, prices[1]-prices[0]);
        vector<int> stock(n,0);
        vector<int> noStock(n,0);

        stock[0] = -prices[0];
        noStock[1] = max(0, stock[0] + prices[1]);
        stock[1] = -min(prices[0],prices[1]);

        for(int i=2;i<n;i++){
            stock[i] = max(stock[i-1], noStock[i-2] - prices[i]);
            noStock[i] = max(noStock[i-1], prices[i] + stock[i-1]);
        }    
        return noStock[n-1];
    }
};
