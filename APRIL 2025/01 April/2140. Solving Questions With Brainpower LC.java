class Solution {
    public long mostPoints(int[][] questions) {
        int N = questions.length;
        long[] dp = new long[N+1];
        int point, brainPower;
        long mostPoint = 0;
        for(int i=N-1; i>=0; i--) {
            point = questions[i][0];
            brainPower = questions[i][1];

            if(i+brainPower+1<N)
                dp[i] = Math.max(dp[i+1], point+dp[i+brainPower+1]);
            else
                dp[i] = Math.max(dp[i+1], point);
            // System.out.println(i+" "+dp[i]+" "+((i+brainPower<N)?dp[i+brainPower]:0));
            mostPoint = Math.max(mostPoint, dp[i]);
        }
        return dp[0];
    }
}
