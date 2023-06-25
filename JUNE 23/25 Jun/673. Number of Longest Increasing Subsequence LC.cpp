class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen=1;
        vector<int> dp(n,1), count(n,1);
        for(int i=1; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[i]>nums[j] && dp[j]+1>dp[i])
                {
                    dp[i] = dp[j] + 1;
                    maxLen = max(maxLen,dp[i]);
                    count[i] = count[j];
                }
                else if(nums[i]>nums[j] && dp[j]+1>=dp[i])
                {
                    count[i]+=count[j];
                }
            }
        }
        int countOfLIS = 0;
        for(int i=0; i<n; i++)
        {
            if(dp[i]==maxLen)
            countOfLIS+=count[i];
            // cout<<i<<" : "<<dp[i]<<" "<<count[i]<<endl;
        }
        return countOfLIS;

    }
};
