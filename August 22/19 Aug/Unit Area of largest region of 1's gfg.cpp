bool check(int x, int y, int n, int m){
        return (x>=0 && y>=0 && x<n && y<m );
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        /*
        -1,-1 -1,0 -1,1
         0,-1  0,0  0,1
         1,-1  1,0  1,1
        */
        
        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};
        
        int maxUnitArea=0;
        int n=grid.size(), m= grid[0].size();
        int nx,ny,Area;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]){
                    
                    Area=0;
                    queue<pair<int,int>> qp;
                    qp.push({i,j});
                    grid[i][j]=-1;
                    while(!qp.empty()){
                        Area++;
                        int x=qp.front().first, y=qp.front().second;
                        qp.pop();
                        for(int i=0;i<8;i++){
                            nx=x+dx[i];
                            ny=y+dy[i];
                            if(check(nx,ny,n,m) && grid[nx][ny]==1){
                                grid[nx][ny]=-1;
                                qp.push({nx,ny});
                            }
                        }
                    }
                    maxUnitArea=max(maxUnitArea,Area);
                    
                }
            }
        }
        
        return maxUnitArea;
        }
        
