class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0], len = nums.size(), moves=0;
        for(int i=1; i<len; i++)
        {
            if(nums[i]>prev)
            {
                prev = nums[i];
                continue;
            }
            prev++;
            moves += (prev-nums[i]);
        }
        return moves;
    }
};
