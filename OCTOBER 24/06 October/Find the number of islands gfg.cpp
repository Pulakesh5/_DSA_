class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int row = grid.size(), col = grid[0].size();
        int countOfIsland = 0;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == '1')
                {
                    // cout<<i<<", "<<j<<" current:"<<endl;
                    queue<vector<int>> positions;
                    positions.push({i, j});
                    grid[i][j] = '$';
                    while(!positions.empty())
                    {
                        vector<int> pos = positions.front();
                        positions.pop();
                        for(int k=0; k<8; k++)
                        {
                            int nx = pos[0] + dx[k];
                            int ny = pos[1] + dy[k];
                            // cout<<nx<<" "<<ny<<" : "endl;
                            if(nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny]=='1')
                            {
                                // cout<<"Pushed "<<nx<<", "<<ny<<endl;
                                positions.push({nx, ny});
                                grid[nx][ny] = '$';
                            }
                        }
                    }
                    countOfIsland++;
                }
            }
        }
        return countOfIsland;
    }
};
