class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;
        int R = isWater.size(), C = isWater[0].size();
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(isWater[i][j])
                {
                    q.push({i, j});
                    isWater[i][j] = 0;
                }
                else
                    isWater[i][j] = -1;
            }
        }
        int dist[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int distance = 1;
        while(!q.empty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                pair<int,int> cell = q.front();
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int nx = cell.first + dist[k][0];
                    int ny = cell.second + dist[k][1];

                    if(nx>=0 && ny>=0 && nx<R && ny<C && isWater[nx][ny]<0)
                    {
                        isWater[nx][ny] = distance;
                        q.push({nx, ny});
                    }
                }
            }
            distance++;
        }
        return isWater;
    }
};
