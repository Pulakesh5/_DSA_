class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1)
	        return arr[0];
	    else if(n==2)
	        return max(arr[0], arr[1]);
	    int maxSum=0;
	    vector<int> dp(n,0);
	    dp[0] = arr[0];
	    dp[1] = max(arr[1], arr[0]);
	    maxSum = max(dp[0], dp[1]);
	    for(int i=2; i<n; i++)
	    {
	        dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
	        maxSum = max(maxSum, dp[i]);
	    }
	    return maxSum;
	    
	}
};
