class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int maxSubArray=0;
        
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(nums1[i]==nums2[j])
                {
                    dp[i][j]=dp[i+1][j+1]+1;
                }
                maxSubArray=max(maxSubArray,dp[i][j]);
            }
        }
        return maxSubArray;
    }
};
