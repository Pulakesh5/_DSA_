class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // checking condition is j-i != nums_j - nums_i
        // => nums_i - i != nums_j - j
        // => n*(n-1)/2 - #pairs such that [nums_i - i == nums_j - j]
        int len = nums.size();

        unordered_map<int,long long> mp;
        for(int i=0; i<len; i++)
            mp[nums[i] - i]++;
        
        long long badPairCount = (1ll*len*(len-1))/2;
        
        for(auto [val, freq]:mp)
            badPairCount -= (freq*(freq-1)/2);

        return badPairCount;
    }
};
