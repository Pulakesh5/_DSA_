class Solution {
public:
    int minDifference(vector<int>& nums) {
        int len = nums.size();
        if(len<=4)
            return 0;
        sort(nums.begin(), nums.end());
        
        if(nums[0]==nums[len-1])
            return 0;
        int minDiff;
        // zero moves
        minDiff = nums[len-1]-nums[0];
        
        // one moves
        minDiff = min(minDiff, nums[len-1] - nums[1]); // move the 1 left element
        minDiff = min(minDiff, nums[len-2] - nums[0]); // move the 1 right element
        
        // two moves
        minDiff = min(minDiff, nums[len-1] - nums[2]); // move the 2 left element
        minDiff = min(minDiff, nums[len-2] - nums[1]); // move the 1 left, 1 right element
        minDiff = min(minDiff, nums[len-3] - nums[0]); // move the 2 right element
        
        // three moves;
        minDiff = min(minDiff, nums[len-1] - nums[3]); // move the 3 left element
        minDiff = min(minDiff, nums[len-2] - nums[2]); // move the 2 left, 1 right element
        minDiff = min(minDiff, nums[len-3] - nums[1]); // move the 1 left, 2 right element
        minDiff = min(minDiff, nums[len-4] - nums[0]); // move the 3 right element
        
        return minDiff;
    }
};
