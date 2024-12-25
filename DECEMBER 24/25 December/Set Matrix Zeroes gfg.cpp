class Solution {
  public:
    int zeroRow[1000], zeroCol[1000];
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        
        int N = mat.size(), M = mat[0].size();
        
        memset(zeroRow, 0, sizeof(zeroRow));
        memset(zeroCol, 0, sizeof(zeroCol));
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(mat[i][j]==0)
                {
                    zeroRow[i] = 1;
                    zeroCol[j] = 1;
                }
            }
        }
        for(int i=0; i<N; i++)
        {
            if(zeroRow[i])
                fill(mat[i].begin(), mat[i].end(), 0);
        }
        for(int j=0; j<M; j++)
        {
            if(zeroCol[j])
            {
                for(int i=0; i<N; i++)
                    mat[i][j] = 0;
            }
        }
    }
};
