class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long preSum=0;
        int len=nums.size();
        long long minArrayValue=0;
        for(int i=0;i<len;i++)
        {
            preSum+=nums[i];
            minArrayValue=max(minArrayValue,(preSum+i)/(i+1));
        }
        return minArrayValue;
    }
};
