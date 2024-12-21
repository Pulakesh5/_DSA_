class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& matrix) {
        // code here
        int n = matrix.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0, k=n-1; j<k; j++, k--)
                swap(matrix[i][j], matrix[i][k]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
