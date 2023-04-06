class Solution {
public:

    bool check(vector<vector<int>>& grid, int x, int y)
    {
        int row=grid.size(), col=grid[0].size();

        if(x<0 || y<0 || x>=col || y>=row) return false;

        if(grid[y][x]==1) return true;
        
        grid[y][x]=1;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<bool> flags(4,false);
        
        for(int k=0;k<4;k++)
            flags[k]=check(grid,x+dx[k],y+dy[k]);

        return flags[0]&& flags[1]&& flags[2]&& flags[3];
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int closedIslands=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0 && check(grid, j, i))
                    closedIslands++;
            }
        }
        return closedIslands;
    }
};
