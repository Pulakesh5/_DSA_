class Solution {
  public:
    // Function to compute the edit distance between two strings
    int LEN1, LEN2;
    int editDistance(string& s1, string& s2) {
        // code here
        LEN1 = s1.size();
        LEN2 = s2.size();
        vector<vector<int>> dp(LEN1+1, vector<int>(LEN2+1,-1));
        // findDistance(s1, s2, 0, 0, dp);
        for(int i=0; i<=LEN1; i++)
        {
            for(int j=0; j<=LEN2; j++)
            {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min({  dp[i-1][j], //remove
                                        dp[i][j-1], //insert
                                        dp[i-1][j-1]//replace
                                        }); 
            }
        }
        return dp[LEN1][LEN2];
    }
};
