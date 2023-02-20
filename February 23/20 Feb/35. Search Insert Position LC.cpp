class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        return pos;
    }
};
