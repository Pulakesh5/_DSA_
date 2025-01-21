class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int len = grid[0].size();
        vector<vector<long long>> dp(2, vector<long long>(len));
        
        dp[0][0] = grid[0][0];
        dp[1][0] = grid[1][0];
        
        for(int i=1; i<len; i++)
        {
            dp[0][i] = (dp[0][i-1] + grid[0][i]);
            dp[1][i] = (dp[1][i-1] + grid[1][i]);
        }

        long long ans = 1e18;
        for(int i=0; i<len; i++)
        {
            ans = min(ans, max(dp[0][len-1] - dp[0][i], (i-1 >= 0) ? dp[1][i-1] : 0)); // robot2 will either get a prefix on row1 or a suffix on row2
        }
        return ans;
    }
};
