class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(), c=matrix[0].size();
        
        for(int i=0;i<r;i++){
            if(matrix[i][0]<=target && matrix[i][c-1]>=target){
                int l=0,r=c-1,mid;
                while(l<=r){
                    mid=l+(r-l)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target) l=mid+1;
                    else r=mid-1;
                }
            }
        }
        return false;
    }
};
/*********************************************************************************************/
class Solution {
public:
    // This approach starts from top-right position and in each iteration it keeps removing eihter one row or one column
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int r=0,c=n-1;
        while(r<m && c>=0){
            if(matrix[r][c]==target) return true;
            target > matrix[r][c] ? r++:c--;
        }
        return false;
    }
};
