class Solution {
    long MOD = (int)1e9+7;
    long[] factorials = new long[100000];
    long factorial(int n)
    {
        if(n==0)
            return 1;
        if(factorials[n]!=-1)
            return factorials[n];
        factorials[n] = (1L*n*factorial(n-1))%MOD;
        return factorials[n];
    }

    long mod_inv(long val)
    {
        int exp = (int)(MOD-2);
        long ans = 1L;
        while(exp>0)
        {
            if((exp&1)==1)
                ans = (ans*val)%MOD;
            val = (val*val)%MOD;
            exp >>= 1;
        }
        return ans;
    }

    long nCr(int n, int r) {
        return ((factorial(n)*mod_inv(factorial(r)))%MOD * mod_inv(factorial(n-r)))%MOD;
    }
    public int idealArrays(int n, int maxValue) {
        Arrays.fill(factorials, -1);

        int[][] dp = new int[maxValue+1][15]; // dp[i][j] keeps count of ways a strict increasing ideal subarray of length j ending with i
        
        int maxLen = Math.min(n,14);
        
        for(int i=1; i<=maxValue; i++)
        {
            dp[i][1] = 1;
            for(int j=2; i*j<=maxValue; j++) // iterates through all possible factors starting with i
            {
                for(int len=1; len<maxLen; len++) // iterates through all possible lengths of subarray
                    dp[i*j][len+1] += dp[i][len];
            }
        }

        long countOfIdealArrays = 0L;
        for(int val=1; val<=maxValue; val++)
        {
            for(int len=1; len<=maxLen; len++)
            {
                countOfIdealArrays = (countOfIdealArrays + nCr(n-1, len-1)*dp[val][len]) % MOD; //use bar and star approach to get to this nCr expression
            }
        }
        return (int)countOfIdealArrays;
    }
}
