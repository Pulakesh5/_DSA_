class Solution {
public:
    const int dx[8] = {-1,-1,-1,1,1,1,0,0};
    const int dy[8] = {-1,0,1,-1,0,1,-1,1};
    bool check(int nx, int ny, int n)
    {
        return nx>=0 && ny>=0 && nx<n && ny<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size(), distance = 0;
        queue<vector<int>> qPoints;
        if(grid[0][0] == 0)
        {
            qPoints.push({0,0});
            // cout<<"pushing "<<0<<" "<<0<<endl;
            grid[0][0] = -1;
            distance = 1;
            // cout<<endl;
        }
        int x, y, nx, ny, qSize;
        while(!qPoints.empty())
        {
            qSize = qPoints.size();
            for(int k=0; k<qSize; k++)
            {
                vector<int> point = qPoints.front();
                qPoints.pop();
                x = point[0];
                y = point[1];
                if(x==(n-1) && y==(n-1))
                    return distance;
                for(int i=0; i<8; i++)
                {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if(check(nx, ny, n) && grid[nx][ny]==0)
                    {
                        qPoints.push({nx, ny});
                        // cout<<"pushing "<<nx<<" "<<ny<<endl;
                        grid[nx][ny] = -1;
                    }
                }
                // cout<<endl;
            }            
            distance++;
        }
        return -1;
    }
};
