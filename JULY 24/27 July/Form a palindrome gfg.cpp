class Solution{
  public:
    int lcs(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int countMin(string str){
    //complete the function here
        string t = str;
        reverse(t.begin(), t.end());
        int res = lcs(str, t);
        // The minimum number of insertions is the length of the string minus the LCS length
        return str.size() - res;
    }
};
