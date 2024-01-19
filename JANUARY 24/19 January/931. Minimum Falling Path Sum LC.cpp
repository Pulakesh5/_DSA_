class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0; j<n; j++)
            dp[n-1][j] = matrix[n-1][j];
        for(int i=n-2; i>-1; i--)
        {
            for(int j=n-1; j>-1; j--)
            {
                dp[i][j] = dp[i+1][j];
                if(j-1>=0)
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                if(j+1<n)
                    dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
                dp[i][j] += matrix[i][j];
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        int minFailingPath=INT_MAX;
        for(int j=0; j<n; j++)
            minFailingPath = min(minFailingPath, dp[0][j]);
        return minFailingPath;
    }
};
