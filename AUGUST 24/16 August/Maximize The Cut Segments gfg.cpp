class Solution
{
    public:
    //Function to find the maximum number of cuts.
     int solve(int n, int x, int y, int z, vector<int> &dp){
        if(n == 0) return 0;
        // if(n < 0) return INT_MIN;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MIN;
        if(n-x >= 0) ans = max(ans, 1+solve(n-x,x,y,z,dp));
        if(n-y >= 0) ans = max(ans, 1+solve(n-y,x,y,z,dp));
        if(n-z >= 0) ans = max(ans, 1+solve(n-z,x,y,z,dp));
        
        return dp[n] = ans;
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int ans = solve(n, x, y, z, dp);
        
        if(ans < 0) return 0;
        return ans;
    }
};
