class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int rotate=0, n=nums.size();
        for(rotate=0;rotate<(n-1);rotate++){
            if(nums[rotate]>nums[rotate+1]){
                break;   
            }
        }
        if(rotate==(n-1))
            return binsearch(nums,target);
        rotate++;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+(n-rotate));
        reverse(nums.begin()+(n-rotate), nums.end());
        return binsearch(nums,target);   
    }
    bool binsearch(vector<int> &nums,int target){
        int mid=-1,l=0,r=nums.size()-1;
        while(l<r){
            mid=l+(r-l+1)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid;
        }
        return (nums[l]==target);
    }
};
