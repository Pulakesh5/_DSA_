class Solution {
  public:
    /*You are required to complete this method*/
    int match(int i, int j, int n, int m, string &pattern, string &str, vector<vector<int>> &dp)
    {
        if(i==n || j==m)
        {
            if(i==n)
            {
                if(j<m)
                    return 0;
                return true;
            }
            
            if(j==m)
            {
                while(i<n) {
                    if(pattern[i++]!='*')
                        return 0;
                }
                return 1;
            }
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(pattern[i]==str[j] || pattern[i]=='?')
            return dp[i][j] = match(i+1, j+1, n, m, pattern, str, dp);
        if(pattern[i]=='*')
            return dp[i][j] = match(i+1, j, n, m, pattern, str, dp) 
                           || match(i, j+1, n, m, pattern, str, dp)
                           || match(i+1, j, n, m, pattern, str, dp);
        
        return dp[i][j] = 0;
    }
    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return match(0, 0, n, m, pattern, str, dp);
    }
};
