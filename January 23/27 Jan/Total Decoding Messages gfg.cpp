	    int mod = 1e9+7;
	    
	    int DP(vector<int> &dp, string str, int n)
	    {
	        if(n==0 || n==1) return 1;
	        
	        if(dp[n]!=-1) return dp[n];
	        
	        int count = 0;
	        
	        if(str[n-1]>='1') count = count + DP(dp, str, n-1)%mod;
	        
	        if(str[n-2]=='1' || str[n-2]=='2' && str[n-1]<='6')
	            count = ( count + DP(dp, str, n-2)%mod )%mod;
	        
	        return dp[n] = count %mod;
	    }
		int CountWays(string str){
		    // Code here
		    int n=str.size();
		    
		    vector<int> dp(n+1,-1);
		    if(str[0]=='0') return 0;
		    
		    return DP(dp,str,n);
		}
