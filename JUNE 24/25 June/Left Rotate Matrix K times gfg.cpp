class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int row = mat.size(), col = mat[0].size();
        k = k%col;
        for(int i=0; i<row; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
            reverse(mat[i].begin(), mat[i].begin()+col-k);
            reverse(mat[i].begin()+col-k, mat[i].end());
        }
        return mat;
    }
};
