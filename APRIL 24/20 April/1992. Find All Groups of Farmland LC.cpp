class Solution {
public:
    bool check(int x, int y, int r, int c)
    {
        return (x>=0 && y>=0 && x<r && y<c);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int r = land.size(), c = land[0].size();
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        vector<vector<int>> farmlands;
        int nx, ny;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(land[i][j] == 1)
                {
                    queue<vector<int>> q;
                    q.push({i,j});
                    land[i][j] = -1;
                    vector<int> start = {i,j};
                    vector<int> last = {i,j};
                    while(!q.empty())
                    {
                        vector<int> cell = q.front();
                        q.pop();
                        for(int j=0; j<4; j++)
                        {
                            nx = cell[0] + dx[j];
                            ny = cell[1] + dy[j];
                            if(check(nx, ny, r, c) && land[nx][ny]==1)
                            {
                                q.push({nx,ny});
                                if(nx>=last[0] && ny>last[1] || ny>=last[1] && nx>last[0])
                                    last = {nx,ny};
                                land[nx][ny] = -1;
                            }
                        }
                    }
                    farmlands.push_back({start[0], start[1], last[0], last[1]});
                }
            }
        }

        return farmlands;
    }
};
