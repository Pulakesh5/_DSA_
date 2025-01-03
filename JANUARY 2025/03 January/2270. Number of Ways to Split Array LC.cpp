class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long Sum = 0ll;
        for(int num:nums)
            Sum += num;
        size_t N = nums.size();
        long long prefixSum = 0ll, ways = 0;
        for(int i=0; i<(N-1); i++)
        {
            Sum -= nums[i];
            prefixSum += nums[i];
            ways += (Sum <= prefixSum);
        }
        return ways;
    }
};
