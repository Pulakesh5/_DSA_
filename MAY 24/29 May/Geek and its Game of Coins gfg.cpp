  public:
    int findWinner(int n, int x, int y) {
        // code here
        // for i = n(5), dp[4] dp[2] dp[1]
        vector<bool> dp(n+1);
        dp[1] = true;
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i] or !dp[i-1];
            if(i-x>=0)
                dp[i] = dp[i] or !dp[i-x];
            if(i-y>=0)
                dp[i] = dp[i] or !dp[i-y];
        }
        return dp[n];
    }
};
