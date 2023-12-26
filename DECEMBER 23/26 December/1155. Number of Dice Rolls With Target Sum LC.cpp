class Solution {
public:
    // int backtrack()
    int numRollsToTarget(int N, int K, int target) {
        vector<vector<long long>> dp(N+1,vector<long long>(target+5));
        dp[0][0] = 1;
        
        int MOD = 1e9+7;
        
        for(int n=1; n<=N; n++)
        {
            for(int t=1;  t<=target; t++)
            {
                for(int k=1; k<=min(t,K); k++)
                    dp[n][t] = (dp[n][t] + dp[n-1][t-k])%MOD;
            }
        }
        return dp[N][target];
    }
};
