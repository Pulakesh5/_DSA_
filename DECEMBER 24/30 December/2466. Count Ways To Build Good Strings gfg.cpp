class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        long long dp[200005]; // no of strings with length i ending with 0 and 1
        const long long MOD = 1e9+7;
        memset(dp, 0ll, sizeof(dp));
        
        dp[0] = 1;
        
        long long count = 0, sum = 0;
        for(int i=1; i<=high; i++)
        {
            sum = 0;
            if(i-zero >= 0)
                sum = (sum + dp[i-zero])%MOD;
            
            if(i-one >= 0)
                sum = (sum + dp[i-one])%MOD;
            dp[i] = sum;
            
            if(i>=low)
            {
                count = (count + sum)%MOD;
            }
        }
        return count;
    }
};
