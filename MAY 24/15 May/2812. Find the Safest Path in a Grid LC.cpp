class Solution {
public:
    int MAX;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    void calculate_safeness(vector<vector<int>> &safeness, vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        queue<vector<int>> q;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j]==1)
                {
                    safeness[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int x, y, nx, ny, qsize;
        int distance = 1;
        while(!q.empty())
        {
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                auto cell = q.front();
                q.pop();
                x = cell[0];
                y = cell[1];
                for(int k=0; k<4; k++)
                {
                    nx = x+dx[k];
                    ny = y+dy[k];
                    if(nx<0 || ny<0 || nx>=row ||ny>=col || safeness[nx][ny]!=MAX)
                        continue;
                    safeness[nx][ny] = distance;
                    q.push({nx,ny});
                }
            }
            distance++;
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        MAX = 2*row+5;

        vector<vector<bool>> visited(row,vector<bool>(col,false));
        vector<vector<int>> safeness(row,vector<int>(col,MAX));
        calculate_safeness(safeness, grid);

        priority_queue<pair<int,vector<int>>> pq;
        int x, y, nx, ny, dist = 2*row+5;
        
        pq.push({safeness[0][0],{0,0}});
        visited[0][0] = true;
        
        while(!pq.empty())
        {
            auto cell = pq.top();
            x = cell.second[0];
            y = cell.second[1];
            dist = cell.first;

            if(x==(row-1) && y==(col-1))
                return dist;
            pq.pop();
            for(int k=0; k<4; k++)
            {
                nx = x+dx[k];
                ny = y+dy[k];

                if(nx<0 || ny<0 || nx>=row ||ny>=col || visited[nx][ny]==true)
                    continue;

                pq.push({min(dist, safeness[nx][ny]),{nx,ny}});
                visited[nx][ny] = true;
            }
        }
        return 0;
    }
};
// 1 1 1
// 0 1 1
// 0 0 0
