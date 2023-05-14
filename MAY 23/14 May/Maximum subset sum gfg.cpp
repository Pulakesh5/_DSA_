    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code 
        // vector<vector<long long, long long>> dp(N+5,vector<long long>(5,0ll));
        // dp[0][0] = A[0];
        // dp[0][1] = 0;
        // for(int i=1; i<N; i++)
        // {
        //     dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + A[i];
        //     dp[i][1] = dp[i-1][0];
        // }
        // return max(dp[N-1][0], dp[N-1][1]);
        vector<pair<long long,long long>> dp(N,{0,0});
        dp[0].first = A[0];
        dp[0].second = 0;
        for(int i = 1; i<N; i++){
            dp[i].first = max(dp[i-1].first,dp[i-1].second)+A[i];
            dp[i].second = dp[i-1].first;
        }
        return max(dp[N-1].first,dp[N-1].second);
        
    }
