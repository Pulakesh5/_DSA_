class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> rows(m,0), cols(n,0);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        vector<vector<int>> diff(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                diff[i][j] = (2*rows[i]-m+2*cols[j]-n);
            }
        }
        return diff;
    }
};
