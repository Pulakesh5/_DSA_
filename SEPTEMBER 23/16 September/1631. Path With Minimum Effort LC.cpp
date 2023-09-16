class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, 1e6));
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int r, c, nr, nc, a, b, effort;
        queue<vector<int>> q;
        q.push({0,0});
        dp[0][0] = 0;
        
        while(!q.empty())
        {
            r = q.front()[0];
            c = q.front()[1];
            q.pop();
            for(vector<int> dir:directions)
            {
                nr = r + dir[0];
                nc = c + dir[1];

                if(nr>-1 && nc>-1 && nr<row && nc<col)
                {
                    a = heights[r][c];
                    b = heights[nr][nc];

                    effort = max(dp[r][c], abs(a-b));

                    if(dp[nr][nc] > effort)
                    {
                        dp[nr][nc] = effort;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return dp[row-1][col-1];
    }
};
