class Solution {
public:
    long long mod = 1e9+7;
    int rec(vector<int> &locations, int start, int finish, int fuel, vector<vector<int>> &dp)
    {
        if(dp[start][fuel]!=-1)
            return dp[start][fuel];
        long long pathCount = 0;
        if(start==finish)
            pathCount = 1;
        int n=locations.size(), cost;
        for(int i=0; i<n; i++)
        {
            cost = abs(locations[i]-locations[start]);
            if(i==start || cost>fuel)
                continue;
            pathCount = ( pathCount + rec(locations, i, finish, fuel - cost, dp) )%mod;
        }
        return dp[start][fuel] = pathCount;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+5,-1));
        return rec(locations, start, finish, fuel, dp);
    }
};
