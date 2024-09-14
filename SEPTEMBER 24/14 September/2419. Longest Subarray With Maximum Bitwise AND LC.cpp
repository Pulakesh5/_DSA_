class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int maxLen = 1, len = 0;
        for(int num:nums)
        {
            if(num == maxElement)
                len++;
            else
                len = 0;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
