class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // sort(arr, arr+n);
        // vector<vector<int>> dp(n+2, vector<int>(sum+2,0));
        // for(int i=0; i<=n; i++)
        //     dp[i][0]=1;
        // // dp[]
        // for(int s=1; s<=sum; s++)
        // {
        //     for(int i=1; i<=n; i++)
        //     {
                
        //         if(arr[i-1]<=s){
        //             dp[i][s]+=dp[i-1][s-arr[i-1]];
        //             // cout<<i<<", "<<s<<" "<<dp[i-1][s-arr[i-1]]<<endl;
        //         }
        //         else
        //             dp[i][s] += dp[i-1][s];
        //     }
        //     cout<<endl;
        // }
        // return dp[n][sum];
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
 
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }
 
        return dp[sum];
	}
	private:
	    const int MOD = 1e9 + 7;
	  
};
