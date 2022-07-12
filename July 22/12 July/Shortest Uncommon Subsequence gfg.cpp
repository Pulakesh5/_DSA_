class Solution {
  public:
   
    int shortestUnSub(string S, string T) {
        // code here
        vector<vector<int>> dp(501,vector<int>(501,1000));
        
        int n=S.size(),m=T.size(),k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                k=j;
                while(k && S[i-1]!=T[k-1])
                    k--;
                if(k==0) dp[i][j]=1;
                else
                    dp[i][j]=min(1+dp[i-1][k-1],dp[i-1][j]);
            }
        }
        return dp[n][m]==1000?-1:dp[n][m];
    }
};
