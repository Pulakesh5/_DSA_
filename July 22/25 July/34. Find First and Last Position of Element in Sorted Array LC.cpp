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
