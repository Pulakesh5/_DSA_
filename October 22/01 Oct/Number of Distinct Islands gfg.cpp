class Solution {
  public:
    int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
    string direction="LRUD";
    void dfs(vector<vector<int>>& grid, int i, int j, string &path)
    {
        int n=grid.size(),m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;
        grid[i][j]=-1;
        for(int k=0;k<4;k++)
        {
            dfs(grid,i+dx[k],j+dy[k],path);
            path.push_back(direction[k]);
        }
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        int distinctIsland=0;
        string path;
        set<string> paths;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    path="";
                    dfs(grid,i,j,path);
                    //cout<<path<<" "<<i<<" "<<j<<endl;
                    if(paths.find(path)==paths.end())
                        distinctIsland++;
                    paths.insert(path);
                }
            }
        }
        return distinctIsland;
    }
};
