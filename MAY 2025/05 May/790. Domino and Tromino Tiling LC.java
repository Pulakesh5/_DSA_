class Solution {
    public int numTilings(int n) {
        long mod = (long)(1e9+7);
        long[][] dp = new long[n+5][3]; // dp[i][0] => ending with complete upto i-1
                                        // dp[i][1] => ending with empty upper half in i-1
                                        // dp[i][2] => ending with empty lower half in i-1

        dp[0][0] = 1L;
        dp[0][1] = 0L;
        dp[0][2] = 0L;

        dp[1][0] = 1L;
        dp[1][1] = 0L;
        dp[1][2] = 0L;

        for(int i=2; i<=n; i++)
        {
            dp[i][0] = (dp[i-1][0]+dp[i-2][0]+dp[i-1][1]+dp[i-1][2])%mod;
            dp[i][1] = (dp[i-2][0]+dp[i-1][2])%mod;
            dp[i][2] = (dp[i-2][0]+dp[i-1][1])%mod;
        }
        
        return (int)dp[n][0];
    }
}
