class Solution{
	public:
    bool check(int nx, int ny, int N){
        return (nx>=0 && nx<N) && (ny>=0 && ny<N);
    }
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    double dp[N][N][steps+1];
	    
	    int dx[]={-1,-1,1,1,-2,-2,2,2};
	    int dy[]={2,-2,2,-2,-1,1,-1,1};
	   
	    //initialization
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++)
	            dp[i][j][0]=1;
	    }
	    
	    double prob=0.0;
	    int nx,ny;
	    for(int s=1;s<=steps;s++){
	        for(int x=0;x<N;x++){
	            for(int y=0;y<N;y++){
	                prob=0.0;
	                for(int i=0;i<8;i++){
	                    nx=x+dx[i];
	                    ny=y+dy[i];
	                    if(check(nx,ny, N))
	                        prob+= dp[nx][ny][s-1]/8.0;
	                }
	                dp[x][y][s]=prob;
	            }
	        }
	    }
	    
	    return dp[start_x][start_y][steps];
	    
	}
};
