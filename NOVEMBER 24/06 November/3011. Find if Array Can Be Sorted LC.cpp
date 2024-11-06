class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        int left = 0, right=left+1;
        size_t len = nums.size();
        while(right<len)
        {
            if(__builtin_popcount(nums[left])==__builtin_popcount(nums[right]))
            {
                right++;
                continue;
            }
            sort(nums.begin()+left, nums.begin()+right);
            left = right;
            right++;
        }
        sort(nums.begin()+left, nums.begin()+right);
        
        return (nums==sorted);
    }
};
