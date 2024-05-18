class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> L, R;
        L = R = vector<int>(prices.size(), 0);
        
        int buyPrice = prices[0];
        for(int i=1; i<len; i++)
        {
            L[i] = max(L[i-1], prices[i]-buyPrice);
            buyPrice = min(buyPrice, prices[i]);
        }
        int sellPrice = prices[len-1];
        for(int i=len-2; i>=0; i--)
        {
            R[i] = max(R[i+1], sellPrice-prices[i]);
            sellPrice = max(sellPrice, prices[i]);
        }
        
        int profit=R[0];
        for(int i=1; i+1<len; i++)
            profit = max(profit, L[i]+R[i+1]);
        return profit;

    }
};
