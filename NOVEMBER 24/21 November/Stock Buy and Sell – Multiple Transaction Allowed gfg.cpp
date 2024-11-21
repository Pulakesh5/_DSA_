class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        size_t len = prices.size();
        int buyPrice = prices[0], sellPrice = prices[0];
        int maxProfit = 0;
        for(int i=1; i<len; i++)
        {
            if(prices[i] < sellPrice)
            {
                maxProfit += (sellPrice - buyPrice);
                buyPrice = prices[i];
                sellPrice = prices[i];
            }
            else
                sellPrice = prices[i];
        }
        maxProfit+= (sellPrice - buyPrice);
        return maxProfit;
    }
};
