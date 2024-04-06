class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<long long> dp(m+1);
		for(int i=0; i<n; i++)
		{
		  //  dp[i+1][j+1] = dp[i][m];
		    for(int j=min(m,i+1); j>0; j--)
		    {
		        dp[j] = max(dp[j], a[i]*b[j-1]+dp[j-1]);
		    }
		}
		return dp[m];
	} 
};
