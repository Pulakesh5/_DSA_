class Solution 
{
    private:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        int freshOranges = 0;
        queue<vector<int>> q;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==1)
                    freshOranges++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        if(freshOranges==0)
            return 0;
        vector<int> cell;
        int qsize = 0, nx, ny;
        int minTimeToRot=-1;
        while(!q.empty())
        {
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                cell = q.front();
                q.pop();
                for(int k=0; k<4; k++)
                {
                    nx = cell[0] + dx[k];
                    ny = cell[1] + dy[k];
                    if(nx<0 || ny<0 || nx>=row || ny>=col || grid[nx][ny]!=1)
                        continue;
                    // cout<<nx<<", "<<ny<<endl;
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                    freshOranges--;
                }
            }
            minTimeToRot++;
            // cout<<minTimeToRot<<endl;
        }
        if(freshOranges)
            return -1;
        return minTimeToRot;
    }
};
