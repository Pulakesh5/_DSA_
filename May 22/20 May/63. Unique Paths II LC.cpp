class Solution {
public:
    int r,c;
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size(); 
        r=row;
        c=col;
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return rec(grid,dp,0,0);
        
    }
    
    int rec(vector<vector<int>> &grid, vector<vector<int>> &dp, int x,int y){
        if(x<0 || x>=r || y<0 ||y>=c || grid[x][y]) return 0;
        if(x==(r-1) && y==(c-1)) return !grid[x][y];
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y]= rec(grid,dp,x+1,y)+rec(grid,dp,x,y+1);
    } 
};
