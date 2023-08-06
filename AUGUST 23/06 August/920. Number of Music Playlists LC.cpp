class Solution {
public:
    const int MOD = 1e9+7;
    long long solve(vector<vector<long long>> &dp, int n, int goal, int k)
    {
        if(n==0 && goal==0)
            return 1ll;
        if(n==0 || goal==0)
            return 0ll;
        if(dp[n][goal]!=-1)
            return dp[n][goal];
        long long pick = solve(dp, n-1, goal-1, k)*n;
        long long notPick = solve(dp, n, goal-1, k)*max(n-k,0);
        return dp[n][goal] = (pick+notPick)%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(n+1,vector<long long>(goal+1,-1));
        return solve(dp, n, goal, k);
    }
};
