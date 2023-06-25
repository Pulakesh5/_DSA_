#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;
    for(int i=1; i<n; i++)
    {
        
        dp[i] = min(dp[i], dp[i-1] + abs(heights[i]-heights[i-1]));
        if(i>=2)
            dp[i] = min(dp[i], dp[i-2] + abs(heights[i] - heights[i-2]));
        // cout<<i<<" : "<<dp[i]<<endl;
    }
    return dp[n-1];
}
