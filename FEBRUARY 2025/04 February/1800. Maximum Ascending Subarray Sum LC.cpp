class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxAscendingSumValue = 0;
        int sum = 0, prev;
        for(int num:nums)
        {
            if(num>prev)
                sum+=num;
            else
                sum = num;
            maxAscendingSumValue = max(maxAscendingSumValue, sum);
            prev = num;
        }
        return maxAscendingSumValue;
    }
};
