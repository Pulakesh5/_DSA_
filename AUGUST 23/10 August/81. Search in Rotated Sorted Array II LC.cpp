class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid;

        while(l<=r)
        {
            mid = l+(r-l)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[l]==nums[mid] && nums[r]==nums[mid])
            {
                l++;
                r--;
            }
            else if(nums[l]<=nums[mid]) //left segment is in order
            {
                if(target>=nums[l] && nums[mid]>target)
                    r = mid-1;
                else
                    l = mid+1;
            }
            else //right segment is in order
            {
                if(target<=nums[r] && nums[mid]<target)
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return false;
    }
};
