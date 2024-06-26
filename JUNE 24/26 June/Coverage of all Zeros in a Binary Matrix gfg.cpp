class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int n = matrix.size(), m = matrix[0].size();
        
        auto check = [&](int r, int c) {
            return (r>=0 && r<n && c>=0 && c<m && matrix[r][c]==1);
        };
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int nx, ny, coverageSum = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==1)
                    continue;
                for(int k=0; k<4; k++)
                {
                    nx = i+dx[k];
                    ny = j+dy[k];
                    coverageSum+=check(nx, ny);
                }
            }
        }
        
        return coverageSum;
    }
};
