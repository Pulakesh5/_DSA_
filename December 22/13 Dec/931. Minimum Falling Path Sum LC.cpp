class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        dp[0]=matrix[0];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((j-1)>=0) dp[i][j]=min(dp[i-1][j-1]+matrix[i][j],dp[i][j]);
                
                dp[i][j]=min(dp[i-1][j]+matrix[i][j],dp[i][j]);
                
                if(j+1<n) dp[i][j]=min(dp[i-1][j+1]+matrix[i][j],dp[i][j]);
            }
        }
        int minPath=INT_MAX;

        for(int j=0;j<n;j++) minPath = min(dp[n-1][j],minPath);

        return minPath;
    }
};
