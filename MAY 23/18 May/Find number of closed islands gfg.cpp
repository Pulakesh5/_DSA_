    bool check(int nx, int ny, int N, int M)
    {
        return nx>=0 && ny>=0 && nx<N && ny<M;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        queue<pair<int,int>> qp;
        bool flag;
        int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
        int count = 0, nx, ny, x, y;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(matrix[i][j]==1)
                {
                    flag = true;
                    qp.push({i,j});
                    matrix[i][j] = -1;
                    
                    while(qp.size())
                    {
                        x = qp.front().first;
                        y = qp.front().second;
                        qp.pop();
                        // if(!flag) continue;
                        for(int k = 0; k<4; k++)
                        {
                            nx = x + dx[k];
                            ny = y + dy[k];
                            if(check(nx,ny,N,M))
                            {
                                if(matrix[nx][ny] == 1)
                                {
                                    qp.push({nx,ny});
                                    matrix[nx][ny] = -1;
                                }
                            }
                            else
                                flag = false;
                        }
                    }
                    // if(flag)
                        // cout<<i<<" "<<j<<" : "<<flag<<endl;
                    count += flag;
                }
                
            }
        }
        return count;
    }
