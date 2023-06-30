class Solution {
public:
    int ROW, COL;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool dfs(vector<vector<int>> &v, vector<vector<bool>> &visited, int r, int c)
    {
        visited[r][c] = true;
        if(r==ROW-1)    return true;
        int nr, nc;
        bool reachable = false;
        
        for(int k=0; k<4; k++)
        {
            nr = r + dx[k];
            nc = c + dy[k];
            if(nr>=0 && nc>=0 && nr<ROW && nc<COL && v[nr][nc]==0 && visited[nr][nc]==0)
                reachable = reachable | dfs(v, visited, nr, nc);
        }
        return reachable;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, h = cells.size()-1, mid, lastDay;
        ROW = row;
        COL = col;
        while(l<=h)
        {
            mid = (l+h)/2;
            vector<vector<int>> v(row, vector<int>(col,0));
            vector<vector<bool>> visited(row, vector<bool>(col,0));
            for(int i=0; i<=mid; i++)
                v[cells[i][0]-1][cells[i][1]-1] = 1;
            bool reachable = false;
            for(int i=0; i<col; i++)
            {
                if(visited[0][i]==0 && v[0][i]==0)
                    reachable = reachable | dfs(v, visited, 0, i);
            }
            if(reachable)
            {
                lastDay = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        return lastDay+1;
    }
};
