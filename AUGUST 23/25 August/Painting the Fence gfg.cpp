class Solution{
    private:
        long long mod = 1e9+7;
    public:
    long long countWays(int n, int k){
        // code here
        if(n==1)
            return k;
        if(n==2)
            return 1ll*k*k;
        
        vector<long long> dp(n+1, 0ll);
        
        dp[0] = 1;
        
        dp[1] = k;
        
        dp[2] = k*k; 
        
        for(int i=3; i<=n; i++)
        {
            dp[i] = (dp[i-1]*(k-1))%mod; // diff color
            dp[i] = (dp[i] + dp[i-2]*(k-1))%mod; // same color
        }
            
        // for(int i=0; i<=n; i++)
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        
        return dp[n];
    }
};
