class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int total = 0;
        for(int rod:rods) total+=rod;

        vector<int> dp(total+1,-1);
        dp[0] = 0;
        int taller, shorter, diff, newDiff;
        for(int rod:rods)
        {
            vector<int> newDp(dp.begin(), dp.end());
            for(int i=0; i<=(total-rod); i++)
            {
                if(newDp[i]<0)
                    continue;
                dp[i+rod] = max(dp[i+rod], newDp[i]);
                dp[abs(i-rod)] = max(dp[abs(i-rod)], newDp[i]+min(i,rod));
            }
        }
        return dp[0];
    }
};
