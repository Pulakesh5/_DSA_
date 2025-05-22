class Solution {
    
    static int lcs(String s, String rev, int s_start, int rev_start)
    {
        int N = s.length();
        int[][] dp = new int[N+1][N+1];
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(s.charAt(i)==rev.charAt(j))
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return dp[N][N];
    }
    static int minDeletions(String s) {
        // code here
        String rev = new StringBuilder(s).reverse().toString();

        return s.length()-lcs(s, rev, 0, 0);
    }
}
