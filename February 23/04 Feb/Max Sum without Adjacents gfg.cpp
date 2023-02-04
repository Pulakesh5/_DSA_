	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n+1);
	    dp[0]=0;
	    dp[1]=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        dp[i+1]=max(dp[i],dp[i-1]+arr[i]);
	    }
	    
	    return max(dp[n],dp[n-1]);
	}
