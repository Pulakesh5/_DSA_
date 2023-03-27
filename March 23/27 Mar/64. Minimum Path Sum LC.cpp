class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((j+1)<n)
                    dp[i][j+1]=min(dp[i][j+1],grid[i][j+1]+dp[i][j]);
                if((i+1)<m)
                    dp[i+1][j]=min(dp[i+1][j],grid[i+1][j]+dp[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
