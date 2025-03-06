class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
