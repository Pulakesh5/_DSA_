class Solution {
public:

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        // vector<vector<int>> visited(n, vector<int>(n));

        int largestIslandSize = 0;

        int islandNo = -1;
        map<int, int> islandSize; // mapping of islandNo to islandSize
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]>0)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = islandNo;
                    // visited[i][j] = 1;
                    int island = 0, nx, ny;
                    while(!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        island++;
                        for(int k=0; k<4; k++)
                        {
                            nx = x+dx[k];
                            ny = y+dy[k];
                            if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]>0)
                            {
                                grid[nx][ny] = islandNo;
                                q.push({nx, ny});
                            }
                        }
                    }
                    islandSize[islandNo] = island;
                    islandNo--;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    set<int> islands;
                    for(int k=0; k<4; k++)
                    {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny])
                        {
                            islands.insert(grid[nx][ny]);
                        }
                    }
                    int newIslandSize = 1;
                    for(auto itr:islands)
                        newIslandSize += islandSize[itr];
                    largestIslandSize = max(largestIslandSize, newIslandSize);
                }
            }
        }
        
        if(largestIslandSize == 0)
            return n*n;
        return largestIslandSize ;

      
    }
};
