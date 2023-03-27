int func(vector<int>&arr,int k,int i,int target,vector<vector<vector<int>>>&dp)
    {
        if(i==0)
        {
         if(k==0&&target==0)
            return 1;
         return 0;
        }
        if(dp[i][target][k]!=-1)
            return dp[i][target][k];
        int pick=0;
        if(arr[i-1]<=target)
        pick= func(arr,k-1,i,target-arr[i-1],dp);
        int not_pick= func(arr,k,i-1,target,dp);
        return dp[i][target][k]= pick+not_pick;
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<int>arr;
        for(int i=1;i<=N;i++)
            arr.push_back(i);
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1, vector<int>(K+1,-1)));
        return func(arr,K,N,N,dp);
    }
