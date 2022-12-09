long long numOfWays(int N, int M)
{
    // write code here
    long long sum=0, count=0;
    
    int mod=1e9+7, ni, nj;
    
    int dx[]={-1,-1,1,1,2,2,-2,-2};
    int dy[]={2,-2,2,-2,1,-1,1,-1};
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            count=1;
            for(int k=0;k<8;k++)
            {
                ni=i+dx[k];
                nj=j+dy[k];
                if(ni>=0 && nj>=0 && ni<N && nj<M) count++;
            }
            sum=sum+(N*M-count);
        }
    }
    
    return sum%mod;
}
