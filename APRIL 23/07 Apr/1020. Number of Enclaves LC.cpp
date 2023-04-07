class Solution {
public:
    bool isValid(int x, int y, int r, int c)
    {
        return x>=0 && y>=0 && x<c && y<r;
    }
    int count(vector<vector<int>>& grid, int x, int y)
    {
        int row=grid.size(), col=grid[0].size();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        pair<int,int> cell;
        int cellX, cellY, nx, ny;
        
        bool flag=true;
        int count=1;
        vector<int> flags={col,-1,row,-1};
        
        queue<pair<int,int>> qp;
        qp.push({y,x});
        grid[y][x]=-1;
        //cout<<"{ "<<x<<", "<<y<<"} :\n";
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
                    if(grid[ny][nx]==1)
                    {
                        qp.push({ny,nx});
                        grid[ny][nx]=-1;
                        count++;
                        //cout<<nx<<" "<<ny<<" "<<count<<endl;
                    }
                }
                else
                {
                    flag=false;
                }
            }
        }
        if(flag)
            return count;
        return 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int closedIslands=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    closedIslands+=count(grid, j, i);
                    //cout<<closedIslands<<endl;
                }
            }
        }
        return closedIslands;
    }
};
