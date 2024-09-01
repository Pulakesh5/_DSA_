class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int N = original.size();
        if(m*n != N)
            return {};
        vector<vector<int>> matrix(m, vector<int>(n));
        int index = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                matrix[i][j] = original[index++];
            }
        }
        return matrix;
    }
};
