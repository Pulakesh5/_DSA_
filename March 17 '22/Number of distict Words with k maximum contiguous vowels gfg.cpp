class Solution
{
  public:
  long long dp[1001][1001], Mod=1000000007;
  long long solve(int N, int cnt, int K){
        if(N==0) return 1;
      
        if(dp[N][cnt]!=-1) return dp[N][cnt];
      
        if(cnt==K) return (21 * solve(N-1,0,K))%Mod;
        
        return dp[N][cnt] =( (21 * solve(N-1,0,K))%Mod + (5 * solve(N-1,cnt+1,K))%Mod ) % Mod;
  }
    int kvowelwords(int N, int K) {
        for(int i=0;i<=N;i++){
            for(int j=0;j<=K;j++)
                dp[i][j]=-1;
        }
        
        return solve(N,0,K)%Mod;
    }
};
