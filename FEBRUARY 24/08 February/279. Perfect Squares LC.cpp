class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(10005,10005);
        dp[1] = 1;
        dp[0] = 0;
        for(int i=2; i<=n; i++)
        {
            for(int j=1;(j*j)<=i; j++)
                dp[i] = min(dp[i],dp[i-j*j]+1);
        }
        for(int i=1; i<=n; i++)
            cout<<i<<" : "<<dp[i]<<endl;
        return dp[n];
    }
};
