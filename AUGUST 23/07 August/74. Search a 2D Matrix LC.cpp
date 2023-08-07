class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low=0, high=(m*n)-1, mid, row, col;
        while(low<=high)
        {
            mid = (low+high)/2;
            row = mid/n;
            col = mid%n;

            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return false;
    }
};
