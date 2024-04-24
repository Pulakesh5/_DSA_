class Solution
{
public:
    int ways(int x, int y)
    {
        //code here.
        const long long MOD = 1e9+7;
        vector<vector<long long>> dp(x+1, vector<long long>(y+1,0));
        for(int i=0; i<=x; i++)
            dp[i][0] = 1;
        for(int j=0; j<=y; j++)
            dp[0][j] = 1;
        for(int i=1; i<=x; i++)
        {
            for(int j=1; j<=y; j++)
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
        return dp[x][y];
    }
};
