// The observation is there is a path between A and B such that [A - X - Y - Z - B]
// Choosing the path A-B, would contribute A^k + B^k + X + Y + Z, so we can pair up any num which contributes positively


#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int len = nums.size();
        ll totalSum = accumulate(nums.begin(), nums.end(), 0ll);
        ll pos_diff=0, pos_count=0, diff, min_abs_diff = INT_MAX;

        for(int num:nums)
        {
            diff = (num^k) - num;
            if(diff>0)
            {
                pos_diff += diff;
                pos_count++;
            }
            min_abs_diff = min(min_abs_diff, abs(diff));
        }
        if(pos_count%2)
            pos_diff -= min_abs_diff;
        return totalSum + pos_diff;
    }
};

// [94]
//  |
// [43] - [92]
//  |
// [78] - [97]
//  |
// [95]

