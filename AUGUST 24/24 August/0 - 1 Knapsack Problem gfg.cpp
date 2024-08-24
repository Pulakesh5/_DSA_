class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int N = wt.size();
        vector<vector<int>> dp(N+1, vector<int>(W+1,0));
        
        for(int i=1; i<=N; i++)
        {
            for(int w=1; w<=W; w++)
            {
                if(wt[i-1]<=w)
                    dp[i][w] = max((dp[i-1][w - wt[i-1]] + val[i-1]), dp[i-1][w]);
                else
                    dp[i][w] = dp[i-1][w];
            }
        }
        return dp[N][W];
    }
};
