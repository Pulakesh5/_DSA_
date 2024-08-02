class Solution {
  public:
    int editDistance(string str1, string str2) {
        // Code here
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0; i<=n; i++)
            dp[i][0] = i;
        for(int i=0; i<=m; i++)
            dp[0][i] = i;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
        
        return dp[n][m];
    }
};
