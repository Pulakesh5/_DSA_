int MOD = 1e9+7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i-1][j])%MOD;
                else
                    dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
            }
        }
        return dp[n][m] % MOD;
    }
};
