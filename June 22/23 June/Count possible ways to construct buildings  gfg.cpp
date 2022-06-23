class Solution{
	public:
    int TotalWays(int N)
	{
	    vector<vector<long long >> dp(N+1,vector<long long>(2,0));
	    dp[0][0]=1;dp[0][1]=1;
	    long long mod=1000000007;
	    for(int i=1;i<=N;i++){
	        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
	        dp[i][1]=dp[i-1][0];
	    }
	    return (dp[N][0]*dp[N][0])%mod;
	}

  //////////////////////////////
	int TotalWays(int N)
	{
	    long long mod=1000000007;
	    long long a=1,b=1;
	    for(int i=1;i<=N;i++){
	        a=(a+b)%mod;
	        b=(a-b);
	    }
	    
	    return (a*a)%mod;
  }  

};
