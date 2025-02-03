class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestSubarray = 1;
        int inc = 1, dec = 1, n = nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i] > nums[i-1])
            {
                dec = 1;
                inc++;
            }
            else if(nums[i] < nums[i-1])
            {
                dec++;
                inc = 1;
            }
            else
            {
                inc = 1;
                dec = 1;
            }
            longestSubarray = max(longestSubarray, max({inc, dec}));
        }
        return longestSubarray;
    }
};
