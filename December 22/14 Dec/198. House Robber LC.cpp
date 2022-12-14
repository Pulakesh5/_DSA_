class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return *max_element(nums.begin(), nums.end());
        
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i+1]=max(nums[i]+dp[i-1],dp[i]);
        }
        return dp[n];
    }
};
