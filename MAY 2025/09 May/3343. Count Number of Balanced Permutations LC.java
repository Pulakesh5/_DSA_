class Solution {
    int MOD = (int)(1e9+7);
    long[] factorial, inverse, inverse_factorial;
    void precompute(int n)
    {
        factorial = new long[n+1];
        inverse = new long[n+1];
        inverse_factorial = new long[n+1];
        factorial[0] = 1;
        inverse[0] = 1;
        inverse_factorial[0] = 1;
        for(int i=1; i<=n; i++)
            factorial[i] = (factorial[i-1]*i)%MOD;
        inverse[1] = 1;
        for(int i=2; i<=n; i++)
            inverse[i] = MOD - (MOD/i)*inverse[MOD%i]%MOD;
        for(int i=1; i<=n; i++)
            inverse_factorial[i] = (inverse_factorial[i-1]*inverse[i])%MOD;
    }
    public int countBalancedPermutations(String num) {
        int N = num.length();
        precompute(N);
        int digitSum = 0;
        for(char ch:num.toCharArray())
            digitSum += (int)(ch-'0');
        if(digitSum%2 == 1)
            return 0;
        
        int halfSum = digitSum/2, halfLen = N/2;
        int[][] dp = new int[halfSum+1][halfLen+1];
        dp[0][0] = 1;

        int[] digitCount = new int[10];
        for(char ch:num.toCharArray())
        {
            int digit = (int)(ch-'0');
            digitCount[digit]++;
            for(int sum = halfSum; sum>=digit; sum--)
            {
                for(int len=halfLen; len>0; len--)
                {
                    dp[sum][len] = (dp[sum][len]+dp[sum-digit][len-1])%MOD;
                }
            }
        }
        long result = dp[halfSum][halfLen];
        result = ((result*factorial[halfLen])%MOD * factorial[N-halfLen])%MOD;
        for(int count:digitCount)
        {
            result = (result * inverse_factorial[count])%MOD;
        }
        return (int)result;
    }
}
