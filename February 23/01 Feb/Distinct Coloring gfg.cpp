    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<long long>> vp(N,vector<long long>(3,0));
        vp[0][0]=r[0];
        vp[0][1]=g[0];
        vp[0][2]=b[0];
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                    vp[i][0]=min(vp[i-1][1],vp[i-1][2])+r[i];
                else if(j==1)
                    vp[i][1]=min(vp[i-1][0],vp[i-1][2])+g[i];
                else
                    vp[i][2]=min(vp[i-1][0],vp[i-1][1])+b[i];
            }
        }
        return min({vp[N-1][0],vp[N-1][1],vp[N-1][2]});
    }
