class Solution {
public:
    bool check(int nx, int ny, int r, int c)
    {
        return nx>=0 && ny>=0 && nx<r && ny<c;
    } 
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> qp;
        
        int r=grid.size(), c=grid[0].size();
        int land=0, water=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j])
                {
                    qp.push({i,j});
                    land++;
                }
                else
                    water++;
            }
        }
        int distance=0, x, y;
        
        vector<int> dx={-1,1,0,0}, dy={0,0,-1,1};
        
        while(!qp.empty())
        {
            int qs = qp.size();
            for(int i=0;i<qs;i++)
            {
                x = qp.front()[0];
                y = qp.front()[1];
                qp.pop();

                for(int k=0;k<4;k++)
                {
                    if(check(x+dx[k], y+dy[k], r, c) && grid[x+dx[k]][y+dy[k]]==0)
                    {
                        grid[x+dx[k]][y+dy[k]]=-1;
                        qp.push({x+dx[k],y+dy[k]});
                    }
                }
            }
            //cout<<distance<<" "<<qs<<endl;
            distance++;
        }
        if(land==(r*c) || water==(r*c))
            return -1;
        return max(0,distance-1);
    }
};
