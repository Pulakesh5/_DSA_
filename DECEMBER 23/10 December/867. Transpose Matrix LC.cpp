class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r=matrix.size(), c=matrix[0].size();
        if(r==c)
        {
            for(int i=0; i<r; i++)
            {
                for(int j=i+1; j<c; j++)
                    swap(matrix[i][j], matrix[j][i]);
            }
            return matrix;
        }
        else
        {
            vector<vector<int>> mat(c, vector<int>(r));
            for(int i=0; i<c; i++)
            {
                for(int j=0; j<r; j++)
                    mat[i][j] = matrix[j][i];
            }
            return mat;
        }
    }
};
