class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len);
        prefix[0] = nums[0];
        for(int i=1; i<len; i++)
            prefix[i] = prefix[i-1] + nums[i];
        vector<int> diffSum;
        int lb, ub, preSum, sufSum;
        for(int i=0; i<len; i++)
        {
            lb = lower_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            ub = upper_bound(nums.begin(), nums.end(), nums[i]) - nums.begin();
            
            preSum =  (lb<1) ? 0 :(prefix[lb-1]);
            preSum = (nums[i]*lb - preSum);
            sufSum = prefix[len-1] - prefix[ub-1];
            sufSum = (sufSum-(len-ub)*nums[i]);

            diffSum.push_back(preSum+sufSum);
        }
        return diffSum;
    }
};
