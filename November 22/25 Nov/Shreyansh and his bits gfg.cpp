class Solution{
public:
    long long dp[100][100];
    
    long long ncr(long long n, long long r)
    {
        if(n < r)   return 0;
        if(r == 0)  return 1;
        if(n == r)  return 1;
        
        if(dp[n][r] != -1)  return dp[n][r];
        
        return dp[n][r] = ncr(n-1, r) + ncr(n-1, r-1);
    }
    
    long long count(long long x) {
        // Code Here
        int bit[64];
        for(int i = 0;i<64;i++) bit[i] = 0;
        long long temp = x;
        int i = 0;
        while(temp > 0)
        {
            bit[i] = temp & 1;
            i++;
            temp = temp >> 1;
        }
        long long ans = 0;
        int oc = 0;
        for(int i = 0;i<64;i++)
        {
            if(bit[i] == 1)
            {
                oc++;
                for(int i = 0;i<100;i++)    
                    for(int j = 0;j<100;j++)
                        dp[i][j] = -1;
                ans = ans + ncr(i, oc);
            }
        }
        return ans;
    }
};
