class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    int maxSum=INT_MIN, minSum=INT_MAX, curMax=0,curMin=0, totalSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            curMax=max(curMax+nums[i],nums[i]);
            curMin=min(curMin+nums[i],nums[i]);
            maxSum=max(maxSum,curMax);
            minSum=min(minSum,curMin);

            totalSum+=nums[i];
        }

        if(maxSum>0) return max(maxSum,totalSum-minSum);
        return maxSum;
    }
};
