class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int Step=0, m=maze.size(), n=maze[0].size();
        int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

        queue<vector<int>> qp;
        qp.push(entrance);

        int sz,x,y,nx,ny;
        while(!qp.empty())
        {
            int sz=qp.size();
            for(int i=0;i<sz;i++)
            {
                auto it=qp.front();
                x=it[0];
                y=it[1];
                qp.pop();
                if(!(x==entrance[0] && y==entrance[1]) && (x==0 || x==(m-1) || y==0 || y==(n-1)))
                    return Step;
                for(int k=0;k<4;k++)
                {
                    nx=x+dx[k];
                    ny=y+dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !(nx==entrance[0] && ny==entrance[1]) && maze[nx][ny]=='.'){
                        qp.push({nx,ny});
                        maze[nx][ny]='$';
                    }
                    
                }
            }
            Step++;
        }

        return -1;
    }
};
