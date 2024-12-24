class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int N = mat.size(), M = mat[0].size();
        int low = 0, high = N-1;
        int row=0;
        while(low<high)
        {
            row = (low+high)/2;
            if(mat[row][M-1]>=x)
            {
                high = row;
            }
            else
                low = row+1;
        }
        if(low==N)
            return false;
            
        row = low;
        low = 0, high = M-1;
        int ind;
        while(low<=high)
        {
            ind = (low+high)/2;
            if(mat[row][ind]==x)
                return true;
            else if(mat[row][ind]<x)
                low = ind+1;
            else
                high = ind-1;
        }
        return false;
        
    }
};
