class Solution {
  public:
    int R,C;
    //vector<vector<int>> mat(250,vector<int>(250,0));
    bool check(int nx,int ny,vector<vector<int>> &A){
        return (nx>=0 && nx<R)&&(ny>=0 && ny<C)&&A[nx][ny]==1;
    }
    int shortestDistance(int row, int col, vector<vector<int>> A, int X, int Y) {
        R=row;
        C=col;
        //mat=A;
        
        queue<pair<int,int>> qp;
        if(A[0][0]==1 && A[X][Y]==1)
            qp.push({0,0});
        else
            return -1;
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
        int cur_x,cur_y;
        int nx,ny;
        int distance=0;
        while(!qp.empty()){
            int sz=qp.size();
            for(int i=0;i<sz;i++){
                pair<int,int> pr=qp.front();
                cur_x=pr.first;cur_y=pr.second;
                qp.pop();
                if(cur_x==X && cur_y==Y) return distance;
                for(int i=0;i<4;i++){
                    nx=cur_x+dx[i];
                    ny=cur_y+dy[i];
                    if(check(nx,ny,A))
                    {
                        qp.push({nx,ny}); A[nx][ny]=0;
                    }
                }
            }
            distance++;
        }
        return -1;
        
    }
};
