class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(),start=INT_MAX,end=-1;
        int l=0,r=n-1,mid;
        while(l<=r){
            mid=(r+l)/2;
            if(nums[mid]==target){
                start=min(start,mid);
                r=mid-1;
            }
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        l=0,r=n-1;
        while(l<=r){
            mid=(r+l)/2;
            if(nums[mid]==target){
                end=max(mid,end);
                l=mid+1;
            }
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        if(start==INT_MAX) start=-1;
        return {start,end};
    }
};
/******************************************************************************************************************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<1) return {-1,-1};
        if(n==1){
            if(nums[0]==target) return {0,0};
            return {-1,-1};
        }
        return binSearch(nums,0,n-1,target);
    }
    
    vector<int> binSearch(vector<int> &nums, int l, int r, int target){
        if(nums[l]==target && nums[r]==target) 
            return {l,r};
        
        if(nums[l] <= target && target<= nums[r]){
            int mid=l+((r-l)>>1);
            vector<int> left = binSearch(nums,l,mid,target);
            vector<int> right = binSearch(nums,mid+1,r,target);
            if(left[0]==-1) return right;
            if(right[0]==-1) return left;
            return {left[0],right[1]};
        }
        
        return {-1,-1};
    }
};
