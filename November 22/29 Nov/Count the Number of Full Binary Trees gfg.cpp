class Solution{
public:
    int N=1e5+5;
    long long mod =1e9+7;
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
        long long minm = 1e9, maxm = -1e9;
        vector<long long> dp(N,0);
        
        for(int i=0;i<n;i++)
        {
            dp[arr[i]]=1;
            if(arr[i]>maxm)
                maxm=arr[i];
            if(arr[i]<minm)
                minm=arr[i];
        }
        long long ans=0;
        for(int i=minm; i<=maxm;i++)
        {
            if(dp[i]!=1 || dp[i]==0) continue;
            
            for(int j=minm;j*j<=i;j++)
            {
                if(i%j==0 && dp[i/j]!=0 && dp[j]!=0)
                {
                    if((i/j)!=j)
                        dp[i]+=(2*dp[i/j]*dp[j]);
                    else
                        dp[i]+=(dp[j]*dp[j]);
                        
                    dp[i]%=mod;
                }
            }
            
            ans+=dp[i];
            ans%=mod;
        }
        
        return ans;
    }
};
