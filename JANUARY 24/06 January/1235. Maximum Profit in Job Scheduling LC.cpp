class Solution 
{
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) 
    {
        int n = s.size();
        vector<int> dp(n,-1);
        
        vector<vector<int>> J;
        for (int i = 0; i < n; ++i) J.push_back({s[i], e[i], p[i]});
        sort(J.begin(), J.end());        
        
        function<int(int)> dfs;
        dfs = [&](int i) -> int
        {
            if (i >= n) return 0;
            if (dp[i] >= 0) return dp[i];
            
            vector<int> v = {J[i][1], 0, 0};
            int k = lower_bound(J.begin(), J.end(), v) - J.begin();
            return dp[i] = max(dfs(i+1), J[i][2] + dfs(k));
        };
        
        return dfs(0);
    }
};
