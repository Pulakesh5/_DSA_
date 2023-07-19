class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int len = A.size();
        string B = A;
        reverse(B.begin(), B.end());
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        
        for(int i=1; i<=len; i++)
        {
            for(int j=1; j<=len; j++)
            {
                if(A[i-1] == B[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[len][len];
    }
};
