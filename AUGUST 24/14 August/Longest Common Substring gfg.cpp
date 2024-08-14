class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int len1 = str1.size();
        int len2 = str2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1));
        int longestSubstrLen = 0;
        for(int i=0; i<=len1; i++)
        {
            for(int j=0; j<=len2; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(str1[i-1]==str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                longestSubstrLen = max(longestSubstrLen, dp[i][j]);
            }
        }
        return longestSubstrLen;
    }
};
