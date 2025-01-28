class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        int maxFish = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(grid[i][j]>0)
                {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] *= -1;
                    int totalFish = 0, nr, nc;
                    while(!q.empty())
                    {
                        pair<int,int> cell = q.front();
                        q.pop();
                        
                        totalFish += (-1*grid[cell.first][cell.second]);

                        for(int k=0; k<4; k++)
                        {
                            nr = cell.first + dx[k];
                            nc = cell.second + dy[k];
                            if(nr>=0 && nc>=0 && nr<R && nc<C && grid[nr][nc]>0)
                            {
                                grid[nr][nc] *= -1;
                                q.push({nr, nc});
                            }
                        }
                    }
                    maxFish = max(maxFish, totalFish);
                }
            }
        }
        return maxFish;
    }
};
