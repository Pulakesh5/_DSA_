class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(), c=matrix[0].size();
        int row=-1;
        int l=0,h=r-1,mid,m;
        
        while(l<=h){
            mid=(l+h)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][c-1])
            {
                l=0;h=c-1;
                while(l<=h){
                    m=(l+h)/2;
                    if(matrix[mid][m]==target)
                        return true;
                    else if(target>matrix[mid][m])
                        l=m+1;
                    else h=m-1;
                }
                
                break;
            }
            else if(matrix[mid][0]>target) h=mid-1;
            else l=mid+1;
        }
        return false;
        
    }
};
