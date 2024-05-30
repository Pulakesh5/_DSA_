class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        if(n<m)
            return 0;
        vector<vector<long>> dp(n+1,vector<long>(m+1,0));
        const int MOD = 1e9+7;
        
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(s2[j-1]==s1[i-1])        
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1])%MOD;
                }
            }
        }
        
        return dp[n][m];
        
    }
};
