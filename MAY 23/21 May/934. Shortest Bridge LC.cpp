class Solution {
public:
    const int dx[4]={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    bool check(int x, int y, int n)
    {
        return x>=0 && x<n && y>=0 && y<n;
    }
    void mark(vector<vector<int>>& grid, int x, int y)
    {
        int n = grid.size();
        queue<vector<int>> qpoint;
        qpoint.push({x,y});
        grid[x][y] = -1;
        vector<int> point;
        int nx, ny;
        while(!qpoint.empty())
        {
            point = qpoint.front();
            qpoint.pop();
            for(int k=0; k<4; k++)
            {
                nx = point[0]+dx[k];
                ny = point[1]+dy[k];
                if(check(nx,ny,n) && grid[nx][ny]==1)
                {
                    grid[nx][ny] = -1;
                    qpoint.push({nx,ny});
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool marked = false;
        for(int i=0; i<n && !marked; i++)
        {
            for(int j=0; j<n && !marked; j++)
            {
                if(grid[i][j]==1)
                {
                    mark(grid, i, j);
                    marked = true;
                }
            }
        }
        queue<vector<int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        int shortestBridge = 0, qsize=0, nx, ny;
        vector<int> point;
        while(!q.empty())
        {
            shortestBridge++;
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                point = q.front();
                q.pop();
                for(int k=0; k<4; k++)
                {
                    nx = point[0] + dx[k];
                    ny = point[1] + dy[k];
                    if(check(nx,ny,n))
                    {
                        if(grid[nx][ny] == 0)
                        {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                        else if(grid[nx][ny] == -1)
                            return shortestBridge - 1;
                    }
                }
            }
        }
        return 0;
    }
};
