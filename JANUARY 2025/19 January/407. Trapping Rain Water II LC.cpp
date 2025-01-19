class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        int trappedRainWater = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for(int i=0; i<m; i++)
        {
            for(int j:{0,n-1})
            {
                pq.push({heightMap[i][j], i, j});
                visited[i][j] = 1;
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j:{0, m-1})
            {
                pq.push({heightMap[j][i], j, i});
                visited[j][i] = 1;
            }
        }

        while(!pq.empty())
        {
            auto cell = pq.top();
            pq.pop();
            int height = cell[0], x = cell[1], y = cell[2];
            for(auto dir:directions)
            {
                int nx = x+dir[0], ny = y + dir[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny])
                {
                    trappedRainWater += max(0, height - heightMap[nx][ny]);
                    pq.push({max(height, heightMap[nx][ny]), nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }

        return trappedRainWater;
    }
};
