class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int count1 = nums1.size(), count2 = nums2.size();
        vector<vector<int>> dp(count1+1, vector<int>(count2+1,0));
        int ans=0;
        for(int i=1;i<=count1;i++)
        {
            for(int j=1;j<=count2;j++)
            {
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                ans = max(ans, dp[i][j]);
            }
        }

        return dp[count1][count2];
    }
};
