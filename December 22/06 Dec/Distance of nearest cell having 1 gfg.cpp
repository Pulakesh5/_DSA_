class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
    
	int rec(vector<vector<int>> &dp, vector<vector<int>> &grid, int i, int j){
	    
	    int n=grid.size(), m=grid[0].size();
	    
	    if(grid[i][j]==1) return dp[i][j]=0;
	    
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	    int nx,ny,dist=INT_MAX;
	    
	    for(int k=0;k<4;k++)
	    {
	        nx=i+dx[k];
	        ny=j+dy[k];
	        
	        if(nx>=0 && nx<n && ny>=0 && ny<m)
	            dist=min(dist,rec(dp,grid,nx,ny));
	    }
	    return dp[i][j]=1+dist;
	    
	}
	
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(), m= grid[0].size();
	    
	    int i,j;
	    vector<vector<int>> res(n,vector<int>(m));
	    
	    vector<vector<int>> vis(n,vector<int>(m));
	    int x[] = {0,0,1,-1};
	    int y[] = {1,-1,0,0};
	    
	    queue<pair<pair<int, int>,int>>q;
	    
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    
	    pair<pair<int, int>,int> p;
	    
	    while(!q.empty()){
	        p = q.front();
	        q.pop();
	        res[p.first.first][p.first.second] = p.second;
	        for(int k=0;k<4;k++){
	                int a = p.first.first+x[k];
	                int b = p.first.second+y[k];
	                
	                if(a<0 || b<0 || a>=n || b>=m || vis[a][b] == 1)
	                    continue;
	                    
	               vis[a][b] = 1;
	               
	               q.push({{a,b},p.second+1});
	        }
	    }
	    
	    return res;
	}
};
