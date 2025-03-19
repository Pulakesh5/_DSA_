class Solution {
  public:
    int dp[1005][205][2];
    int solve(vector<int> &prices, int k, int index, bool canBuy)
    {
        if(index>=prices.size() || k<=0)
            return 0;
        
        if(dp[index][k][canBuy]!=-1)
            return dp[index][k][canBuy];
            
        int pick = INT_MIN, notPick = INT_MIN;
        if(canBuy)
        {
            pick = -prices[index]+solve(prices, k, index+1, false);
            notPick = solve(prices, k, index+1, canBuy);
        } else {
            pick = prices[index] + solve(prices, k-1, index+1, true);
            notPick = solve(prices, k, index+1, canBuy);
        }
        return dp[index][k][canBuy] = max(pick, notPick);
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(prices, k, 0, true);
    }
};
