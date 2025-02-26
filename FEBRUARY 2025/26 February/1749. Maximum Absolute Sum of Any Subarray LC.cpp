class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int mx_sum = 0, mn_sum = 0;
        for(int num:nums)
        {
            mx_sum += num;
            mn_sum += num;
            
            if(mx_sum > maxSum)
                maxSum = mx_sum;
            if(mn_sum < minSum)
                minSum = mn_sum;

            if(mx_sum < 0)
                mx_sum = 0;
            if(mn_sum > 0)
                mn_sum = 0;
        }
        return max(maxSum, abs(minSum));
        
    }
};
