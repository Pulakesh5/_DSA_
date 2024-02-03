class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        int len = arr.size();
        vector<int> dp(len+5);
        int windowMax, bestMax;
        for(int i=1; i<=len; i++)
        {
            windowMax = 0;
            bestMax = 0;
            for(int k=1; k<=K && (i-k)>=0; ++k)
            {
                windowMax = max(windowMax, arr[i-k]);
                bestMax = max(bestMax, dp[i-k] + windowMax*k);
            }
            dp[i] = bestMax;
        }

        return dp[len];
    }
};
// 0 -> 
// 1 -> 0
// 2 -> 1, 0
