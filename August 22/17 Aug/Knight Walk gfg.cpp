class Solution {
public:
    int dist[1001][1001];
    bool check(int x,int y, int n){
        return (x>0 && y>0 && x<=n && y<=n);
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    // Code here
	   int dx[]={-1,-1,+1,+1,-2,-2,+2,+2};
	   int dy[]={+2,-2,+2,-2,-1,+1,-1,+1};
	   
	   vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
	   for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) dist[i][j]=(1e9+7);
	   
	   queue<pair<int,int>> q;
	   q.push({KnightPos[0],KnightPos[1]});
	   visited[KnightPos[0]][KnightPos[1]]=true;
	   dist[KnightPos[0]][KnightPos[1]]=0;
	   
	   int nx,ny;
	   int step=0;
	   while(!q.empty()){
	       int q_size=q.size();
	       for(int i=0;i<q_size;i++){
	           pair<int,int> pr=q.front();
	           q.pop();
	           int x=pr.first,y=pr.second;
	            for(int j=0;j<8;j++){
	                nx=x+dx[j];
	                ny=y+dy[j];
	                if(check(nx,ny,n) && !visited[nx][ny])
	               {
	                   if(dist[nx][ny]>(1+dist[x][y]))
	                   {
	                        q.push({nx,ny});
	                        visited[nx][ny]=true;
	                        dist[nx][ny]=(1+dist[x][y]);
	                   }
	               }     
	            }
	       }
	       step++;
	   }
	   int tx=TargetPos[0], ty=TargetPos[1];
	   return (dist[tx][ty]==(1e9+7)?-1:dist[tx][ty]);
	}
};
