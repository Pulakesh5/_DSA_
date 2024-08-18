class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long> (n,0));
        for(int i=0; i<n; i++)
            dp[0][i] = points[0][i];
        
        for(int i=1; i<m; i++)
        {
            vector<long long> leftDP(n,-1), rightDP(n,-1);
            
            leftDP[0] = dp[i-1][0];
            for(int k=1; k<n; k++)
                leftDP[k] = max(leftDP[k-1], dp[i-1][k]+k);
            
            rightDP[n-1] = dp[i-1][n-1] - n + 1;
            for(int k=n-2; k>=0; k--)
                rightDP[k] = max(rightDP[k+1], dp[i-1][k]-k);

            for(int j=0; j<n; j++)
                dp[i][j] = max(leftDP[j]-j, rightDP[j]+j) + points[i][j];

        }

        return *max_element(dp[m-1].begin(), dp[m-1].end());
    }
};
