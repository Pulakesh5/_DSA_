class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> cuts = {x, y, z};
        vector<int> dp(n+5,INT_MIN);
        for(auto it:cuts)
            if(it<=n)
                dp[it] = 1;
        dp[0] = 0;
        for(int len=1; len<=n; len++)
        {
            // cout<<" : "<<len<<" : \n";
            for(auto it:cuts)
            {
                if(it<=len && dp[len-it]!=INT_MIN)
                {
                    dp[len] = max(dp[len], dp[len-it]+dp[it]);
                    // cout<<it<<" : "<<dp[it]<<" "<<dp[len]<<endl;
                }
            }
            
        }
        if(dp[n]==INT_MIN)
            return 0;
        return dp[n];
    }
};
