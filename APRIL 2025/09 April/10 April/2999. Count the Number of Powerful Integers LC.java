class Solution {
    //we can keep dp with length, first digit as parameter then 
    private long countValidNumber(long value, int limit, String s)
    {
        String numStr = Long.toString(value);
        int prefixLength = numStr.length() - s.length();

        if(prefixLength < 0)
            return 0L;
        // dp[i][tight] => if tight=0 can use any digit upto limit
        //                 else respect
        long[][] dp = new long[prefixLength+1][2]; 

        dp[prefixLength][0] = 1L;
        dp[prefixLength][1] = (numStr.substring(prefixLength).compareTo(s) >= 0) ? 1L:0L;

        for(int i=prefixLength-1; i>=0; i--)
        {
            int digit = numStr.charAt(i)-'0';
            dp[i][0] = (limit+1)*dp[i+1][0];

            if(digit<=limit)
                dp[i][1] = digit*dp[i+1][0] + dp[i+1][1];
            else
                dp[i][1] = (limit+1)*dp[i+1][0];
        }


        return dp[0][1];
    }
    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        return countValidNumber(finish, limit, s) - countValidNumber(start-1, limit, s);
    }
}
