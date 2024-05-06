class Solution{
    private:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    vector<char> direction = {'U', 'D', 'L', 'R'};
    bool check(int x, int y, int n)
    {
        return !(x>=n || y>=n || x<0 || y<0);
    }
    void backtrack(int x, int y, vector<vector<int>> &matrix, vector<vector<bool>> &visited, string path, vector<string> &paths)
    {
        int n = visited.size();
        if(x==n-1 && y==n-1)
        {
            paths.push_back(path);
            return;
        }
        int nx, ny;
        for(int k=0; k<4; k++)
        {
            nx = x+dx[k];
            ny = y+dy[k];
            if(check(nx, ny, n) && visited[nx][ny]==false && matrix[nx][ny]==1)
            {
                visited[nx][ny] = true;
                path.push_back(direction[k]);
                backtrack(nx, ny, matrix, visited, path, paths);
                visited[nx][ny] = false;
                path.pop_back();
            }
        }
    }
    /*
    1 0 0 0
    1 1 0 1
    1 1 0 0
    0 1 1 1*/
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return {};
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        string path = "";
        vector<string> paths;
        visited[0][0] = true;
        backtrack(0, 0, m, visited, path, paths);
        
        return paths;
    }
};
