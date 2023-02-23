    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<long long>> paths(n,vector<long long>(m,0));
        
        long long mod=1e9+7;
        
        paths[n-1][m-1]=grid[n-1][m-1];
        
        for(int r=n-1;r>=0;r--)
        {
            for(int c=m-1;c>=0;c--)
            {
                if(r==(n-1) && c==(m-1)) 
                    continue;
                if(grid[r][c]==0)
                    continue;
                if((r+1)<n && grid[r+1][c]==1)
                    paths[r][c]=(paths[r][c] + paths[r+1][c])%mod;
                if((c+1)<m && grid[r][c+1]==1)
                    paths[r][c]=(paths[r][c] + paths[r][c+1])%mod;
            }
        }
        return paths[0][0];
    }
