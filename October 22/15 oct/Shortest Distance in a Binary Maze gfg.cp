int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> dest) {
        // code here
        if(grid[source.first][source.second]==0) return -1;
        
        queue<pair<int,int>> qp;
        qp.push({source.first,source.second});
        grid[source.first][source.second]=-1;
        
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        
        int n=grid.size(),m=grid[0].size();
        int distance=0;
        
        while(!qp.empty())
        {
            int qs=qp.size();
            for(int i=0;i<qs;i++)
            {
                auto pr=qp.front();
                qp.pop();
                if(pr.first==dest.first && pr.second==dest.second) return distance;
                for(int k=0;k<4;k++)
                {
                    int nx=pr.first+dx[k];
                    int ny=pr.second+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=-1;
                        qp.push({nx,ny});
                    }
                }
            }
            distance++;
        }
        
        return -1;
    }
