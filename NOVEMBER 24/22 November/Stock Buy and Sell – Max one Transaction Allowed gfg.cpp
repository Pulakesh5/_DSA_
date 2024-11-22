class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int maxProfit = 0;
        int buyPrice = prices[0], sellPrice = prices[0];
        size_t len = prices.size();
        for(int i=1; i<len; i++)
        {
            if(prices[i]<buyPrice)
            {
                maxProfit = max(maxProfit, sellPrice-buyPrice);
                buyPrice = prices[i];
                sellPrice = prices[i];
            }
            else
                sellPrice = max(sellPrice, prices[i]);
            maxProfit = max(maxProfit, sellPrice - buyPrice);
        }
        return maxProfit;
    }
};
