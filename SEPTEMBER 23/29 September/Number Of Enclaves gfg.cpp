class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        int enclaves=0, landCell=0, nx, ny;
        bool flag;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    queue<vector<int>> q;
                    q.push({i,j});
                    grid[i][j] = -1;
                    landCell=0;
                    flag = true;
                    while(!q.empty())
                    {
                        auto point = q.front();
                        q.pop();
                        landCell++;
                        // cout<<point[0]<<", "<<point[1]<<" : "<<landCell<<endl;
                        for(int k=0; k<4; k++)
                        {
                            nx = point[0] + dx[k];
                            ny = point[1] + dy[k];
                            if(nx>-1 && ny>-1 && nx<n && ny<m)
                            {
                                if(grid[nx][ny]==1)
                                {
                                    q.push({nx, ny});
                                    grid[nx][ny] = -1;
                                }
                            }
                            else
                                flag = false;
                        }
                    }
                    
                    if(flag)
                        enclaves+=landCell;
                    // cout<<flag<<" "<<enclaves<<endl;
                }
            }
        }
        
        return enclaves;
    }
};
