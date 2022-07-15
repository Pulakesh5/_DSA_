class Solution {
public:
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int island=0,maxIsland=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    island=dfs(grid,i,j);
                    maxIsland = max(maxIsland,island);
                }
            }
        }
        return maxIsland;
    }
    
    int dfs(vector<vector<int>>& grid,int i,int j){
        int row=grid.size(), col=grid[0].size();
        int island=1;
        grid[i][j]=-1;
        for(int k=0;k<4;k++){
            if(i+dx[k]>=0 && i+dx[k]<row&&j+dy[k]>=0 && j+dy[k]<col&&grid[i+dx[k]][j+dy[k]]==1){
                island+=dfs(grid,i+dx[k],j+dy[k]);
            }
        }
        return island;
    }
};
