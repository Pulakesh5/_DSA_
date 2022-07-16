class Solution {
public:
    long  mod=1e9+7;
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    int dp[55][55][55];
    int dfs(int m, int n, int maxMove,int sr, int sc){
        if(!(sr>=0 && sr<m && sc>=0 && sc<n)) return 1;
        
        if(maxMove<=0) return 0;
        
        if(dp[sr][sc][maxMove]!=-1) return dp[sr][sc][maxMove];
        long ans=0;
        int nr,nc;
        // for(int i=0;i<4;i++){
        //     nr=sr+dy[i];
        //     nc=sc+dx[i];
        //     ans= (ans + findPaths(m,n,maxMove-1,nr,nc)%mod)%mod;
        // }
        int up= dfs(m,n,maxMove-1,sr-1,sc);
        int down = dfs(m,n,maxMove-1,sr+1,sc);
        int right = dfs(m,n,maxMove-1,sr,sc+1);
        int left = dfs(m,n,maxMove-1,sr,sc-1);
        ans= (up%mod +down%mod +right%mod +left%mod)%mod;
        dp[sr][sc][maxMove]=ans%mod;
        return dp[sr][sc][maxMove];
    }
    
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,maxMove,sr,sc);
    }
};
