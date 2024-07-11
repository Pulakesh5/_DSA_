class Solution {
  public:
    int dfs(vector<vector<int>> &grid, int i, int j, int n, int islandNo)
    {
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0 || grid[i][j]==islandNo)
            return 0;
        grid[i][j] = islandNo;
        int a = dfs(grid, i, j-1, n, islandNo);
        int b = dfs(grid, i, j+1, n, islandNo);
        int c = dfs(grid, i-1, j, n, islandNo);
        int d = dfs(grid, i+1, j, n, islandNo);
        return 1+a+b+c+d;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        unordered_map<int,int> mp;
        int n = grid.size();
        int islandNo = 2, size, ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    size = dfs(grid, i, j, n, islandNo);
                    mp[islandNo] = size;
                    ans = max(ans, size);
                    islandNo++;
                }
                
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                unordered_set<int> neighbors;
                int maxSize = 0;
                if(grid[i][j]==0)
                {
                    if(i>0) neighbors.insert(grid[i-1][j]);
                    if(j>0) neighbors.insert(grid[i][j-1]);
                    if(i<n-1) neighbors.insert(grid[i+1][j]);
                    if(j<n-1) neighbors.insert(grid[i][j+1]);
                    
                    for(auto it:neighbors)
                    {
                        if(mp.find(it)!=mp.end())
                        {
                            maxSize += mp[it];
                        }
                    }
                    maxSize++;
                    ans = max(ans, maxSize);
                }
            }
        }
        return ans;
    }
};
