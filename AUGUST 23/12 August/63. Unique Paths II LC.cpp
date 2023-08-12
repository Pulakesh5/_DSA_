class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int M, N, nx, ny;
        M = grid.size(); 
        N = grid[0].size();
        
        vector<vector<int>> pathCount(M+1, vector<int>(N+1,0));
        
        pathCount[0][1] = (grid[0][0]==0);
        // or pathCount[1][0] = (grid[0][0]==0);
        for(int i=1; i<=M; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(grid[i-1][j-1] == 0)
                    pathCount[i][j] = (pathCount[i-1][j] + pathCount[i][j-1]);   
            }
        }
        return pathCount[M][N];
    }
};
