int countDistinctWays(int nStairs) {
    //  Write your code here.
    /*
    vector<long long> dp(nStairs+5);
    long long mod = 1e9+7;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=nStairs; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    return dp[nStairs];
    */
    if(nStairs<=1)
        return 1;
    long long mod = 1e9+7;
    long long a = 0, b = 1, c = 1;

    for(int i=2; i<=nStairs; i++)
    {
        c = (c + b)%mod;
        b = (c - b + mod)%mod;
        a = (c - b + mod)%mod;
    }
    return c;
}
