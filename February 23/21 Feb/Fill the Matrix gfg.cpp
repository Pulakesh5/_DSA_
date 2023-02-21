    // bool check(int nx, int ny, int N, int M)
    // {
    //     return nx>=0 && ny>=0 && nx<N && ny<M;
    // }
    int minIteration(int N, int M, int x, int y){    
        // code here
        // vector<int> dx={-1,1,0,0};
        // vector<int> dy={0,0,-1,1};

        // queue<vector<int>> qpoint;
        // vector<vector<int>> filled(N,vector<int>(M,0));
        
        // qpoint.push({x-1,y-1});
        // filled[x-1][y-1]=1;
        
        // int qs,iteration=0,nx,ny, notFilled=N*M-1;
        // bool fill=false;
        // vector<int> point;
        // while(!qpoint.empty() && notFilled)
        // {
        //     qs=qpoint.size();
        //     fill=false;
        //     for(int i=0;i<qs;i++)
        //     {
        //         point = qpoint.front();
        //         qpoint.pop();
        //         for(int k=0;k<4;k++)
        //         {
        //             nx=point[0]+dx[k];
        //             ny=point[1]+dy[k];
        //             if(check(nx,ny,N,M) && filled[nx][ny]==0)
        //             {
        //                 fill=true;
        //                 qpoint.push({nx,ny});
        //                 filled[nx][ny]=1;
        //                 notFilled--;
        //             }
        //         }
        //     }
        //     iteration+=fill;
        // }
        int iteration=0;
        if(N==1 && M==1) return 0;
        int X=x-1, Y=y-1;
        iteration=max(iteration,X+Y);//Top Left
        iteration=max(iteration,X+M-Y-1);//Top Right
        iteration=max(iteration,N-X-1+Y);//Bottom Left
        iteration=max(iteration,N-X-1+M-Y-1);//Top Left
        return iteration;
    }
