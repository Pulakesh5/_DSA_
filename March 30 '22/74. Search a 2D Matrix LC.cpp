class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target)     {
        int m=a.size(),n=a[0].size();
        int l=0,h=m*n-1;
        int mid=-1;
        while(l<=h){
            mid = l+(h-l+1)/2;
            int val=a[mid/n][mid%n];
            if(val==target) return true;
            else if(val>target) h=mid-1;
            else l=mid+1;
        }
        return false;
        
        
    }
};
