class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            vector<int> dp(n+1);
            for(int i=1; i<=n; i++)
                dp[i] = i;
            for(int i=4; i<=n; i++)
            {
                dp[i] = max(dp[i], (dp[i/2]+dp[i/3]+dp[i/4]));
                // cout<<" "<<i<<" : "<<dp[i/2]<<" "<<dp[i/3]<<" "<<dp[i/4]<<endl;
                // cout<<dp[i]<<endl;
            }
            return dp[n];
        }
};
