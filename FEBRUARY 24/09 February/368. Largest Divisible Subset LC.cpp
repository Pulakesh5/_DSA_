class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,vector<int>>> dp(n);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
            dp[i] = {1,{nums[i]}};
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 && dp[i].first<dp[j].first+1)
                {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = dp[j].second;
                    dp[i].second.push_back(nums[i]);
                }
            }
        }
        int subsetSize = 1, divisibleSubset = 0;
        for(int i=0; i<n; i++)
        {
            if(dp[i].second.size()>subsetSize)
            {
                subsetSize++;
                divisibleSubset = i;
            }
        }
        return dp[divisibleSubset].second;
    }
};
