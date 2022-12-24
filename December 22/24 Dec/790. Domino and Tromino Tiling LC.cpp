class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(n+5,0);
        long long mod=1e9+7;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        if(n<=2) return dp[n];
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-3]+dp[i-1]*2)%mod;
        }
        return dp[n];
    }
};
