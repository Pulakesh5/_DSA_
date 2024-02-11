class Solution {
public:
    int dc[3] = {-1,0,1};
    int dp[72][72][72];
    int R, C;
    int cherryPick(int r, int c1, int c2, vector<vector<int>> &grid)
    {
        if(r==R)
            return 0;
        if(dp[r][c1][c2]!=-1)
            return dp[r][c1][c2];
        else
        {

        }
        int nc1, nc2, ans=0;
        for(int dc1:dc)
        {
            for(int dc2:dc)
            {
                nc1 = c1+dc1;
                nc2 = c2+dc2;
                if(nc1>=0 && nc2>=0 && nc1<C && nc2<C)
                {
                    ans = max(ans, cherryPick(r+1, nc1, nc2, grid));
                }
            }
        }
        ans += (c1==c2)? (grid[r][c1]) : (grid[r][c1]+grid[r][c2]);
        return dp[r][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        R = grid.size();
        C = grid[0].size();
        return cherryPick(0,0,C-1,grid);
    }
};
