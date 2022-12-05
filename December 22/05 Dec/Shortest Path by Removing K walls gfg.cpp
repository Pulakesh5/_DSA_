    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        if(mat[0][0]==1) return -1;
        
        queue<vector<int>> qv;
        vector<vector<int>> visited(n,vector<int> (m,-1));
        
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        int nx, ny, step=0, qsize;
        
        qv.push({0,0,k}); // {sx,sy,k,step}
        //mat[0][0]=-1;
        
        while(!qv.empty())
        {
            qsize=qv.size();
            for(int i=0;i<qsize;i++)
            {
                vector<int> cell = qv.front();
                qv.pop();
                
                if(cell[0]==(n-1) && cell[1]==(m-1)) return step;
                
                //mat[cell[0]][cell[1]]=-1;
                
                for(int k=0;k<4;k++)
                {
                    nx=cell[0]+dx[k];
                    ny=cell[1]+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]<cell[2]-mat[nx][ny])
                    {
                        qv.push({nx,ny,cell[2]-mat[nx][ny]});
                        visited[nx][ny]=cell[2]-mat[nx][ny];
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
