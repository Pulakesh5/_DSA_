long long int  countPS(string s)
    {       
       //Your code here
       long long mod=1e9+7;
       int n=s.size();
       vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
       for(int i=0;i<n;i++)
            dp[i][i]=1ll;
        
        for(int L=2;L<=n;L++)
        {
            for(int i=0;i<=(n-L);i++)
            {
                int j=i+L-1;
                if(s[i]==s[j]) dp[i][j]= (dp[i+1][j]+dp[i][j-1]+1ll)%mod;
                else dp[i][j] = (dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+mod)%mod;
            }
        }
        
        return dp[0][n-1];
    }
