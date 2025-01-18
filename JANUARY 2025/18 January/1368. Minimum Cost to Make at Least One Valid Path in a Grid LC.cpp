class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dy[] = {1,-1,0,0};
        int dx[] = {0,0,1,-1};
        
        // priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        deque<pair<int,int>> dq;
        // vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int dp[m][n];

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                dp[i][j] = INT_MAX;

        dp[0][0] = 0;
        dq.push_back({0,0}); // {x, y}
        
        while(dq.size())
        {
            auto cell = dq.front();
            int x = cell.first, y = cell.second, nx, ny;
            int cost = dp[x][y];
            dq.pop_front();

            // if(cost > dp[x][y]) // already found better path
            //     continue;

            for(int k=0; k<4; k++) // try all direction
            {
                nx = x+dx[k];
                ny = y+dy[k];
                if(nx>=0 && ny>=0 && nx<m && ny<n)
                {
                    int weight = ((grid[x][y]-1) != k); // increase cost by 1 if direction does not match sign of grid
                    if(cost+weight < dp[nx][ny])
                    {
                        dp[nx][ny] = cost + weight;
                        if(weight)
                            dq.push_back({nx, ny});
                        else
                            dq.push_front({nx, ny});
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};
