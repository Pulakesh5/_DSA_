class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int nx, ny;
        int subIslandCount = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid2[i][j]==1)
                {
                    // cout<<i<<" "<<j<<endl;
                    bool notSubIsland = !(grid1[i][j]==1);
                    queue<vector<int>> q;
                    q.push({i, j});
                    grid2[i][j] = -1;
                    
                    while(!q.empty())
                    {
                        vector<int> position = q.front();
                        q.pop();
                        for(int k=0; k<4; k++)
                        {
                            nx = position[0] + dx[k];
                            ny = position[1] + dy[k];
                            if(nx>=0 && ny>=0 && nx<m && ny<n && grid2[nx][ny]==1)
                            {
                                q.push({nx, ny});
                                grid2[nx][ny] = -1;
                                if(grid1[nx][ny]==0)
                                    notSubIsland = true;
                            }
                        }
                    }

                    if(!notSubIsland)
                        subIslandCount+=1;
                }
            }
        }
        return subIslandCount;
    }
};
