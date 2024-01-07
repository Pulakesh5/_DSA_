class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int N=nums.size(), diff;
        vector<map<int,int>> dp(N);
        long long arthSubSeq=0;
        for(int i=0; i<N; i++)
        {
            for(int j=i-1; j>-1; j--)
            {
                diff = nums[j] - nums[i];
                arthSubSeq += dp[j][diff];
                dp[i][diff]+=dp[j][diff];
                dp[i][diff]++;
                // cout<<j<<", "<<i<<" : "<<dp[j][diff]<<" "<<dp[i][diff]<<endl;
            }
        }
        return arthSubSeq;
    }
};
