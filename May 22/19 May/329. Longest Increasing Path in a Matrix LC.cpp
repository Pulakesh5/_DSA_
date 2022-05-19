class Solution {
public:
    //Best use of dfs and dp together
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int dfs(vector<vector<int>>& matrix,vector<vector<int>> &dp, int x,int y){
        if(dp[x][y]) return dp[x][y];
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=matrix.size()||ny<0 || ny>=matrix[0].size()) continue;
            if(matrix[nx][ny]>matrix[x][y])
            dp[x][y]=max(dp[x][y],dfs(matrix,dp,nx,ny));
        }
        return ++dp[x][y]; 
    }
     
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size(), col=matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans = max(ans,dfs(matrix,dp,i,j));
            }
        }
        return ans;
        
    }
};
