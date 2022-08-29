class Solution {
public:
    bool check(int nx,int ny,int m, int n)
    {
        return nx>=0 && ny>=0 && nx<m && ny<n;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int NumofIsland=0;
        int m=grid.size(), n= grid[0].size();
        queue<pair<int,int>> qp;
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        int x,y,nx,ny;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    qp.push({i,j});
                    NumofIsland++;
                    while(!qp.empty())
                    {
                        pair<int,int> frnt=qp.front();
                        x=frnt.first;
                        y=frnt.second;
                        qp.pop();
                        for(int k=0;k<4;k++)
                        {
                            nx=x+dx[k];
                            ny=y+dy[k];
                            if(check(nx,ny,m,n) && grid[nx][ny]=='1')
                            {
                                qp.push({nx,ny});
                                grid[nx][ny]='0';
                            }
                        }
                    }
                }
            }
        }
        return NumofIsland;
    }
};
