class Solution {
  public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int MinimumEffort(int rows, int cols, vector<vector<int>> &heights) {
        //int ans = INT_MAX;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0});
        //visited[0][0] = true;
        
        while (!pq.empty()) {
            auto x = pq.top();
            int diff = x[0];
            int dx = x[1];
            int dy = x[2];
            pq.pop();
            if (dx == rows - 1 && dy == cols - 1) {
                return diff;
            }
            if(visited[dx][dy]){
                continue;
            }
            visited[dx][dy]=true;
            for(int i=0;i<4;i++){
                int nr=dx+dir[i].first;
                int nc=dy+dir[i].second;
                if(nr>=0 && nr<rows && nc>=0 && nc<cols && !visited[nr][nc]){
                    int nd=abs(heights[dx][dy]-heights[nr][nc]);
                    nd=max(nd,diff);
                    pq.push({nd,nr,nc});
                }
            }
        }
        return 0;
    }
};
