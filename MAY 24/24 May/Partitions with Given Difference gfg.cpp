class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        const int MOD = 1e9+7;
        int sum=0;
        for(int i=0; i<n; i++) 
            sum+=arr[i];
        if((sum-d)%2!=0 || (sum-d)<0)
            return 0;
        s1 + s2 = su
        int target = (sum+d)/2;
        vector<int> dp(target+1);
        
        
        dp[0] = 1;
        for(int num:arr)
        {
            for(int j=target; j>=num;j--)
            {
                dp[j] = (dp[j]+dp[j-num])%MOD;
            }
        }
        return dp[target];
    }
};
