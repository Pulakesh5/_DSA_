class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(4,n+1));
        dp[0][1] = dp[0][1] = dp[0][2] = 1;
        dp[0][nums[0]]=0;
        for(int i=1;i<n; i++)
        {
            for(int k=1; k<=3; k++)
            {
                dp[i][1] = dp[i-1][1] + (nums[i]!=1);
                dp[i][2] = min(dp[i-1][1],dp[i-1][2]) + (nums[i]!=2);
                dp[i][3] = min({dp[i-1][1],dp[i-1][2],dp[i-1][3]}) + (nums[i]!=3);
            }
        }
        return min({dp[n-1][1], dp[n-1][2], dp[n-1][3]});
    }
};
