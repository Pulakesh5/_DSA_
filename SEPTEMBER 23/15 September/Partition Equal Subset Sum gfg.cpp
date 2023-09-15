class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum = 0;
        for(int i=0; i<N; i++)
            totalSum+=arr[i];
        if(totalSum&1)
            return 0;
        
        sort(arr, arr+N);
        int half = totalSum/2;
        
        vector<vector<bool>> dp(N+1, vector<bool>(half+1, false));
        for(int i=0; i<=N; i++)
            dp[i][0] = true;
            
        for(int s=1; s<=half; s++)
        {
            for(int i=1; i<=N; i++)
            {
                if(arr[i-1]<=s)
                {
                    dp[i][s] = dp[i][s] or dp[i-1][s-arr[i-1]];
                }
                dp[i][s] = dp[i][s] or dp[i-1][s];
            }
        }
        for(int i=1; i<=N; i++)
        {
            if(dp[i][half])
                return true;
        }
        return false;
        
    }
};
