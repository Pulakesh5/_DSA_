int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        if(s1[0]==s2[0])
            dp[1][1] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // cout<<i<<" "<<j<<" : "<<dp[i][j]<<", "<<dp[i][j-1]<<", "<<dp[i-1][j]<<endl;
            }
        }
        return dp[n][m];
    }
