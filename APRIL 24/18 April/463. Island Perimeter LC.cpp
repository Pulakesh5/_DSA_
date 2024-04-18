class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int countPerimeter(vector<vector<int>> &grid, int x, int y)
    {
        // cout<<"called with "<<x<<' '<<y<<endl;
        int row = grid.size(), col = grid[0].size();
        int perimeter = 0;
        queue<vector<int>> q;
        q.push({x,y});
        grid[x][y] = -1;
        int qsize, nx, ny;
        while(!q.empty())
        {
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                vector<int> cell = q.front();
                q.pop();
                // cout<<cell[0]<<", "<<cell[1]<<" : ";
                for(int k=0; k<4; k++)
                {
                    nx = cell[0] + dx[k];
                    ny = cell[1] + dy[k]; 

                    if(nx<0 || ny<0 || nx>=row || ny>=col || grid[nx][ny]==0)
                        perimeter++;
                    else if(grid[nx][ny] == 1)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = -1;
                    }
                }
                cout<<perimeter<<endl;
            }
        }
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==1)
                {
                    return countPerimeter(grid, i, j);
                }
            }
        }

        return 0;
    }
};
