class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));

        for(int i=0; i<m; i++)
            dp[0][i] = grid[0][i];
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int mx = INT_MAX;
                for(int k=0; k<m; k++)
                {
                    if(j==k)
                        continue;
                    mx = min(mx, dp[i-1][k]);
                }
                
                dp[i][j] = mx + grid[i][j];
                // cout<<i<<", "<<j<<" : "<<mx<<" "<<dp[i][j]<<endl;
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
