vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};
class Solution{   
public:
    bool check(int nx, int ny, int N, int M)
    {
        return nx>=0 && ny>=0 && nx<N && ny<M;
    }
    
    void BFS(queue<vector<int>> &qv, vector<vector<bool>> &visited, vector<vector<int>> &mat)
    {
        int N = visited.size(), M=visited[0].size();
        int nx, ny;
        vector<int> pos;
        while(!qv.empty())
        {
            pos = qv.front();
            
            qv.pop();
            for(int k=0;k<4;k++)
            {
                nx = pos[0] + dx[k];
                ny = pos[1] + dy[k];
                
                if(check(nx, ny, N,M) && !visited[nx][ny] && mat[nx][ny]>=mat[pos[0]][pos[1]])
                {
                    qv.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
    }
    
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        vector<vector<bool>> visited_indian(N,vector<bool>(M,false));
        vector<vector<bool>> visited_arabian(N,vector<bool>(M,false));
        
        
        queue<vector<int>> qv;
        for(int i=0;i<N;i++)
        {
            qv.push({i,0});
            visited_indian[i][0]=true;
        }
        
        for(int j=1;j<M;j++)
        {
            qv.push({0,j});
            visited_indian[0][j]=true;
        }
        BFS(qv,visited_indian,mat);
        
        
        for(int i=0;i<N;i++)
        {
            qv.push({i,M-1});
            visited_arabian[i][M-1]=true;
        }
        
        for(int j=M-2;j>=0;j--)
        {
            qv.push({N-1,j});
            visited_arabian[N-1][j]=true;
        }
        BFS(qv,visited_arabian,mat);
        
        int cellCount=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cellCount+=(visited_indian[i][j] && visited_arabian[i][j]);

        return cellCount;
    }
};
