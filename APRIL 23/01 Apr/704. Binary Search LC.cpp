class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int midIndex;
        while(l<=r)
        {
            midIndex=(l+r)/2;
            if(nums[midIndex]==target)
                return midIndex;
            else if(nums[midIndex]<target)
                l=midIndex+1;
            else
                r=midIndex-1;
        }
        return -1;
    }
};
