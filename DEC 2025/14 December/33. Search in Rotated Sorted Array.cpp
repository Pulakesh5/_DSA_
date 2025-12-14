class Solution {
public:
    int search(vector<int>& nums, int target) {
        // observation : Half of the array is always sorted
        int l = 0, r = nums.size()-1, mid;
        while(l<=r) {
            mid = l+(r-l)/2;
            if(nums[mid]==target) return mid; // found target

            if(nums[l]<=nums[mid]) // left half of array is sorted
            {
                if(nums[l]<=target && target<nums[mid]) // target is strictly in the left side
                    r = mid-1;
                else
                    l = mid+1;
            } else { // right half sorted
                if(nums[mid]<target && target<=nums[r]) // target is strictly in right half
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
    }
};
