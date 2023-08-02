bool check(int nx, int ny, int N, int M)
    {
        return nx>=0 && ny>=0 && nx<N && ny<M;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]!=1)
            return -1; 
        queue<vector<int>> qp;
        qp.push({0,0});
        A[0][0]=-1;
        vector<int> cell;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int distance = 0, qs, nx, ny;
        while(!qp.empty())
        {
            qs = qp.size();
            for(int i=0; i<qs; i++)
            {
                cell = qp.front();
                qp.pop();
                if(cell[0]==X && cell[1]==Y)
                    return distance;
                for(int k=0; k<4; k++)
                {
                    nx = cell[0]+dx[k];
                    ny = cell[1]+dy[k];
                    if(check(nx,ny,N,M) && A[nx][ny]==1)
                    {
                        A[nx][ny] = -1;
                        qp.push({nx, ny});
                    }
                }
            }
            distance++;
        }
        return -1;
    }
