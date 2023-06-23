class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> dp[n+1];
        int diff, count, ans = 0;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                diff = nums[i] - nums[j];
                count = 1;
                if(dp[j].count(diff))
                    count = dp[j][diff];
                dp[i][diff] = 1 + count;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
