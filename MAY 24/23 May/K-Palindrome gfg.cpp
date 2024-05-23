class Solution{
public:
    int removeImposter(string &str, int l, int r, vector<vector<int>> &dp)
    {
        if(l>=r)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        if(str[l]==str[r])
            return dp[l][r] = removeImposter(str, l+1, r-1, dp);
        else
            return dp[l][r] = 1 + min(removeImposter(str,l,r-1,dp), removeImposter(str,l+1,r,dp));
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return (removeImposter(str, 0, n-1, dp)<=k);
    }
};
