class Solution {
  public:

    int min_operations(vector<int>& nums) {
        // Code here
        int len = nums.size();
        vector<int> dp(len+1,1);
        int LIS = 1;
        for(int i=1; i<len; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j] && (nums[i]-nums[j])>=(i-j))
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    LIS = max(LIS, dp[i]);
                }
            }
        }
        return (len-LIS);
    }
};
