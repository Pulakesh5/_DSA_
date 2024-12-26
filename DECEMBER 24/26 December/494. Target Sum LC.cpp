class Solution {
public: 
    int backtrack(vector<int> &nums, int index, int target)
    {
        if(index==nums.size())
        {
            return (target==0);
        }
        return backtrack(nums, index+1, target+nums[index]) + backtrack(nums, index+1, target-nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, 0, target);
    }
};
