class Solution {
    int[][] dp = new int[101][101];
    int mod = (int)(1e9+7);
    int solve(int n, int r)
    {
        if(r==0 || r==n)
            return 1;
            
        if(dp[n][r]!=-1)
            return dp[n][r];
            
        return dp[n][r] = (solve(n-1,r-1)+solve(n-1,r))%mod;
    }
    public int nCr(int n, int r) {
        // code here
        if(r>n)
            return 0;
        for(int[] row:dp)
            Arrays.fill(row, -1);
        
        return solve(n,r);
    }
}
