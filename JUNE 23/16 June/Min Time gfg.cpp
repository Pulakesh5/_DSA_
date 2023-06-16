class Solution {
    long long dfs(int i, int j, int n, vector<vector<int>> &g, vector<vector<long long>> &dp) {
        if(i == n) return abs(g[i - 1][j]);
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = min(abs(g[i - 1][j] - g[i][0]) + g[i][1] - g[i][0] + dfs(i + 1, 1, n, g, dp),
                              abs(g[i - 1][j] - g[i][1]) + g[i][1] - g[i][0] + dfs(i + 1, 0, n, g, dp));
    } 
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        map<int, vector<int>> m;
        for(int i=0; i<n; i++) m[types[i]].push_back(locations[i]);
        
        vector<vector<int>> g;
        for(auto i : m) {
            int mn = 1e9, mx = -1e9;
            for(int j : i.second) {
                mn = min(mn, j);
                mx = max(mx, j);
            }
            g.push_back({mn, mx});
        }
        int l = g.size();
        vector<vector<long long>> dp(l, vector<long long>(2, -1));
        return min(abs(g[0][0]) + g[0][1] - g[0][0] + dfs(1, 1, l, g, dp),
                   abs(g[0][1]) + g[0][1] - g[0][0] + dfs(1, 0, l, g, dp));
    }
}; 
