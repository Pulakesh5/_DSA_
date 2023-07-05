class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prevSub = 0, sub = 0, longest = 0;
        for(int num:nums)
        {
            if(num)
            {
                sub++;
                continue;
            }
            longest = max(longest, prevSub+sub);
            prevSub = sub;
            sub = 0;
        }
        if(sub==nums.size())
            return sub-1;
        longest = max(longest, prevSub+sub);
        return longest;
    }
};
