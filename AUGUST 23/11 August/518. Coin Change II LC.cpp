class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // sort(coins.begin(), coins.end());
        int len = coins.size();
        vector<vector<int>> dp(amount+5,vector<int>(len+1,0));

        for(int i=0; i<=len; i++)
            dp[0][i] = 1;
        for(int i=0; i<=amount; i++)
            dp[i][0] = 0;
        dp[0][0] = 1;

        for(int i=1; i<=amount; i++)
        {
            for(int j=1; j<=len; j++)
            {
                if(i>=coins[j-1])
                    dp[i][j] = (dp[i-coins[j-1]][j] + dp[i][j-1]);
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[amount][len];
    }
};
