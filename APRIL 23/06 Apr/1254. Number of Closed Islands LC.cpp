class Solution {
public:
    bool isValid(int x, int y, int r, int c)
    {
        return x>=0 && y>=0 && x<c && y<r;
    }
    bool check(vector<vector<int>>& grid, int x, int y)
    {
        int row=grid.size(), col=grid[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        pair<int,int> cell;
        int cellX, cellY, nx, ny;
        bool flag=true;
        vector<int> flags={col,-1,row,-1};//{left,right,bottom,top}
        queue<pair<int,int>> qp;
        qp.push({y,x});
        grid[y][x]=-1;
        //cout<<x<<" "<<y<<endl;
        while(!qp.empty())
        {
            cell=qp.front();
            cellY=cell.first;
            cellX=cell.second;
            qp.pop();
            for(int k=0;k<4;k++)
            {
                nx=cellX+dx[k];
                ny=cellY+dy[k];
                if(isValid(nx, ny, row, col))
                {
                    if(grid[ny][nx]==0)
                    {
                        qp.push({ny,nx});
                        grid[ny][nx]=-1;
                    }
                }
                else
                {
                    flag=false;
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int closedIslands=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0 && check(grid, j, i))
                {
                    //cout<<"successful\n";
                    closedIslands++;
                }
            }
        }
        return closedIslands;
    }
};
