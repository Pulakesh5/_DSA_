    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    long long sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    sort(arr,arr+n);
	    
	    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
	    
	    for(int j=0;j<=sum;j++) dp[0][j]=false;
        for(int i=0;i<=n;i++) dp[i][0]=true;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        for(int s=sum/2;s>=0;s--)
        {
            if(dp[n][s])
            {
                //cout<<s<<endl;
                return sum-2*s;
            }
        }
        
        
        return dp[n][sum];
	} 
