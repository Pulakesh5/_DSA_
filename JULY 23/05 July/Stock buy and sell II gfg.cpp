class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here;
        int buyPrice = prices[0], sellPrice = 0, maxProfit = 0;
        for(int i=1; i<n; i++)
        {
            if(prices[i]>buyPrice)
                maxProfit+=(prices[i]-buyPrice);
            buyPrice = prices[i];
        }
        maxProfit += max(0,buyPrice - prices[n-1]);
        return maxProfit;
    }
};
