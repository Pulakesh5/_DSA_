class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int INF =m+n+1;
        vector<vector<int>> distance(m, vector<int>(n,INF));
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        int x, y, nx, ny;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    distance[i][j] = 0;
                    for(int k=0; k<4; k++)
                    {
                        nx = i+dx[k];
                        ny = j+dy[k];
                        if(nx>=0 && nx<m && ny>=0 && ny<n)
                        {
                            if(mat[nx][ny]==1 && distance[nx][ny]==INF)
                            {
                                distance[nx][ny] = 1;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        int qs, level = 1;
        pair<int, int> cell;
        while(!q.empty())
        {
            qs = q.size();
            for(int i=0; i<qs; i++)
            {
                cell = q.front();
                x = cell.first;
                y = cell.second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    nx = x+dx[k];
                    ny = y+dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n)
                    {
                        if(mat[nx][ny]==1 && distance[nx][ny]==INF)
                        {
                            distance[nx][ny] = level+1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            level++;
        }
        return distance;
    }
};
