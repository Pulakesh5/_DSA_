
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,0);
        for(int i=0; i<n; i++)
            dp[i+1] = price[i];
        for(int len=1; len<=n; len++)
        {
            
            for(int i=1; i<=len; i++)
            {
                dp[len] = max(dp[len], dp[len-i] + dp[i]);
            }
        }
        return dp[n];
    }
};
