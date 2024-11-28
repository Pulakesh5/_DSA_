class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minObs(m, vector<int>(n,-1));
        minObs[0][0] = grid[0][0];
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({minObs[0][0], 0, 0});
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int x, y, nx, ny;
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            x = node[1]; y = node[2];
            // cout<<x<<" "<<y<<" : minObs "<<minObs[x][y]<<endl;
            for(int k=0; k<4; k++)
            {
                nx = x+dx[k];
                ny = y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    if(minObs[nx][ny]==-1 || minObs[nx][ny]>node[0]+grid[nx][ny])
                    {
                        minObs[nx][ny] = node[0] + grid[nx][ny];
                        pq.push({minObs[nx][ny], nx, ny});
                        // cout<<"Pushing "<<minObs[nx][ny]<<"[ "<<nx<<" "<<ny<<" ]"<<endl;
                    }
                }
            }
        }
        return minObs[m-1][n-1];
    }
};
