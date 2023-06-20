class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> preSum(n+5,0);
        for(int i=1; i<=n; i++)
            preSum[i] = preSum[i-1] + nums[i-1];
        vector<int> averages(n,-1);

        for(int i=k; i<(n-k); i++)
        {
            averages[i] = (preSum[i+k+1] - preSum[i-k])/(2*k+1);
        }
        return averages;
    }
};
