class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int localMax;
        vector<vector<int>> convolution(row-2,vector<int>(col-2));
        for(int i=0; i<row-2; i++)
        {
            for(int j=0; j<col-2; j++)
            {
                localMax = INT_MIN;
                for(int a=0; a<3; a++)
                {
                    for(int b=0; b<3; b++)
                    {
                        localMax = max(localMax,grid[i+a][j+b]);
                    }
                }
                convolution[i][j] = localMax;
            }
        }
        return convolution;
    }
};
