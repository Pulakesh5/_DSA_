class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int len = cuts.size();
        vector<vector<int>> dp(105,vector<int>(105,0));
        int Cost;
        for(int left=len-1; left>=0; left--)
        {
            for(int right=left+1; right<len; right++)
            {
                for(int i=left+1; i<right; i++)
                {
                    Cost = (cuts[right] - cuts[left]) + dp[left][i] + dp[i][right];
                    dp[left][right] = min(dp[left][right] == 0? INT_MAX : dp[left][right] , Cost);
                }
            }
        }

        return dp[0][len-1];
    }
};
