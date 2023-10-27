class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        int len = s.size();
        vector<vector<int>> dp(len+5, vector<int>(len+5,0));
        string rev(s.rbegin(), s.rend());
        int pLen=1;
        
        for(int i=0; i<=len; i++)
        {
            for(int j=0; j<=len; j++)
            {
                if(i==0 || j==0)
                    continue;
                else if(s[i-1]==rev[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return len-dp[len][len];
    } 
};
