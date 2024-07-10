class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        vector<vector<int>> dp(n,vector<int>(m));
        int maxSize = 0;
        //initialize first column
        for(int i=0; i<n; i++)
        {
            dp[i][0] = mat[i][0];
            maxSize = max(dp[i][0], maxSize);
        }
        //initialize first row
        for(int i=0; i<m; i++)
        {
            dp[0][i] = mat[0][i];
            maxSize = max(dp[0][i], maxSize);
        }
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(mat[i][j])
                {
                    dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]})+1;    
                    maxSize = max(maxSize, dp[i][j]);
                }
                
            }
        }
        return maxSize;
        // vector<vector<int>> matSum(n+2,vector<int>(m+2));
        // for(int i=0; i<n; i++)
        // {
        //     matSum[i+1] = matSum[i];
        //     for(int j=0; j<m; j++)
        //         matSum[i+1][j+1] += ((matSum[i+1][j] - matSum[i][j]) + mat[i][j]);
        // }
        
        // for(int i=1; i<=n; i++)
        // {
        //     for(int j=1; j<=m; j++)
        //         cout<<matSum[i][j]<<"  ";
        //     cout<<endl;
        // }
        return -1;
    }
};
