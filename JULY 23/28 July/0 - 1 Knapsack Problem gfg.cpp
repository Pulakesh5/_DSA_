//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int N) 
    { 
        vector<vector<int>> dp(N+1,vector<int>(W+1,0));
        for(int n=1; n<=N; n++)
        {
            for(int w=1; w<=W; w++)
            {
                if(wt[n-1]<=w)
                    dp[n][w] = max(val[n-1]+dp[n-1][w-wt[n-1]], dp[n-1][w]);
                else
                    dp[n][w] = dp[n-1][w];
            }
        }
        return dp[N][W];
    }
};
