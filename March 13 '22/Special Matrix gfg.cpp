class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
        int dp[n+1][m+1];
        int blocked[n+1][m+1];
        memset(dp,0,sizeof(dp));
        memset(blocked,0,sizeof(blocked));
        
        for(auto &it:blocked_cells){
            blocked[it[0]-1][it[1]-1]=1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int p=0,q=0;
                dp[i][j]=0;
                
                if(blocked[i][j]) continue;
                
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    if(i>0)
                        p=dp[i-1][j];
                    if(j>0) 
                        q=dp[i][j-1];
                    dp[i][j]=(p+q)%(1000000007);
                }
            }
        }
        
        return dp[n-1][m-1];
	}
};
