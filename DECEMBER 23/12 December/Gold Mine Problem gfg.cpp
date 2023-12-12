class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0; i<n; i++)  
            dp[i][0] = M[i][0];
        for(int j=1; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
                if(i-1>=0)
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
                if(i+1<n)
                    dp[i][j] = max(dp[i][j],dp[i+1][j-1]);
                dp[i][j]+=M[i][j];
            }
        }
        
        int maxGold = 0;
        for(int i=0; i<n; i++)
            maxGold = max(maxGold, dp[i][m-1]);
        
        return maxGold;
    }
};
