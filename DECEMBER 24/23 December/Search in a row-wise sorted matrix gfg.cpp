class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++)
        {
            int lb = lower_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
            if(lb==m)
                continue;
            if(mat[i][lb]==x)
                return true;
        }
        return false;
    }
};
