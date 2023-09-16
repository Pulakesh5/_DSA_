class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        long long MOD = 1e9+7;
        long long  dp[n+1];
        
        memset(dp, 0, sizeof(dp));
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for(int i=4; i<=n; i++)
            dp[i] = (dp[i-1]+dp[i-2] + dp[i-3])%MOD;
        
        return dp[n];
    }
};
