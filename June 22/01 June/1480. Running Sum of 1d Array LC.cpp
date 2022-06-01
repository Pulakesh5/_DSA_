class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> presum(n);
        presum[0]=nums[0];
        
        for(int i=1;i<n;i++)
            presum[i]=presum[i-1]+nums[i];
        
        return presum;
    }
};
