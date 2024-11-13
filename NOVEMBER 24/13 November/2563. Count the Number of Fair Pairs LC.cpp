class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        size_t len = nums.size();
        long long pairCount = 0;
        for(int i=0; i<len ; i++) 
        {
            int lb = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
            int ub = lower_bound(nums.begin()+i+1, nums.end(), upper-nums[i]+1) - nums.begin();

            pairCount += (ub-lb);
        }
        // pairCount/=2;
        return pairCount;
    }
};
