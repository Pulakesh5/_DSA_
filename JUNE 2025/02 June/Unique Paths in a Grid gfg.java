class Solution {
    public int countUniquePaths(int[][] grid, int[][] dp, int r, int c, int N, int M)
    {
        if(!(r>=0 && r<N && c>=0 && c<M && grid[r][c]==0))
            return 0;

        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int countPath = 0;
        
        countPath += countUniquePaths(grid, dp, r, c+1, N, M); // go right
        countPath += countUniquePaths(grid, dp, r+1, c, N, M); // go down
        
        return dp[r][c] = countPath;
    }
    
    public int uniquePaths(int[][] grid) {
        // code here
        int N = grid.length, M = grid[0].length;
        int[][] dp = new int[N+5][M+5];
        
        for(int[] row:dp)
            Arrays.fill(row, -1);
        
        if(grid[0][0]==1 || grid[N-1][M-1]==1)
            return 0;
        
        dp[N-1][M-1] = 1;
        
        return countUniquePaths(grid, dp, 0, 0, N, M);
    }
};
