class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        vector<int> dp(1005,0);
        int longestSubseqLen = 1;
        
        for(int i=0; i<n; i++)
        {
            dp[a[i]] = max(dp[a[i]], 1);
            
            dp[a[i]] = max({dp[a[i]-1]+1, dp[a[i]+1]+1, dp[a[i]]});
            
            longestSubseqLen = max(longestSubseqLen, dp[a[i]]);
        }
        
        return longestSubseqLen;
        
    }
};
