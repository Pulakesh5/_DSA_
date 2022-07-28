class Solution{
public:
    int Mod=1e9+7;
    long long nCr(int n, int r){
        if(r>(n-r)) r=n-r;
        int dp[r+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=min(i,r);j>0;j--){
                dp[j]=(dp[j] + dp[j-1])%Mod;
            }
        }
        return dp[r];
    }
    int knots(int M, int N, int K){
        // code here
        return (nCr(M,K)*nCr(N,K))%Mod;
        
    }
};
