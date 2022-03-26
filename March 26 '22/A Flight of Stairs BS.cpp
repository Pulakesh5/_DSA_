int solve(int n) {
    int mod=1e9+7;
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    return dp[n];
}
