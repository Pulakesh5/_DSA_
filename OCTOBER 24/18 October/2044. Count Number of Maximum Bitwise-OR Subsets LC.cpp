class Solution {
public:
    void all_subset(vector<int> &nums, int index, int subsetOR, int &target, int &maxORcount) {
        if(subsetOR == target)
        {
            maxORcount += 1<<(nums.size()-index);
            return;
        }
        if(index == nums.size())
            return;
        all_subset(nums, index+1, subsetOR | nums[index], target, maxORcount);
        all_subset(nums, index+1, subsetOR, target, maxORcount);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxORcount = 0, maxOR = 0;
        for(int num:nums)
            maxOR = maxOR | num;
        all_subset(nums, 0, 0, maxOR, maxORcount);
        return maxORcount;
    }
};
