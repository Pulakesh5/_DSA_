class Solution {
public:
    int M, N;
    int dp[51][51][51];
    int mod = 1e9+7;
    int dfs(int sr, int sc, int maxMove)
    {
        if(!(sr>=0 && sr<M && sc>=0 && sc<N))
            return 1;
        if(maxMove==0)
            return 0;
        if(dp[sr][sc][maxMove]!=-1)
            return dp[sr][sc][maxMove];

        long long  up = dfs(sr, sc-1, maxMove-1);
        long long down = dfs(sr, sc+1, maxMove-1);
        long long left = dfs(sr-1, sc, maxMove-1);
        long long  right = dfs(sr+1, sc, maxMove-1);

        return dp[sr][sc][maxMove] = (up + down + left + right)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        memset(dp, -1, sizeof(dp));
        return dfs(startRow, startColumn, maxMove);
    }
};
