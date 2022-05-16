class Solution {
public:
    bool possible(int x,int y, int n){
        return (x>=0 && x<n)&&(y>=0 && y<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        //cout<<n;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        
        queue<pair<int,int>> q;
        int dx[]={-1,0,1,-1,1,-1,0,1};
        int dy[]={1,1,1,0,0,-1,-1,-1};
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        
        if(grid[0][0]==0) q.push({0,0});
        visited[0][0]=true;
        int path=0;
        int x,y,nx,ny;;
        while(!q.empty()){
            
            int sz=q.size();
            path++;
            for(int i=0;i<sz;i++){
                pair<int,int> curr=q.front();
                q.pop();
                x=curr.first;
                y=curr.second;
                //cout<<x<<" "<<y<<'\n';
                if(x==(n-1) && y==(n-1)){
                    while(!q.empty()) q.pop();
                    break;
                }               
                for(int j=0;j<8;j++){
                    //cout<<"for\n";
                    nx=x+dx[j];
                    ny=y+dy[j];
                    if(possible(nx,ny,n)&&grid[nx][ny]==0&&!visited[nx][ny]){
                        //cout<<nx<<" "<<ny<<'\n';
                        q.push({nx,ny});visited[nx][ny]=true;
                    } 
                }
            }
            
        }
        if(x==(n-1) && y==(n-1))
            return path;
        else
            return -1;
    }
};
