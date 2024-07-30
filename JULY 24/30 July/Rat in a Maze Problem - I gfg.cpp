class Solution {
  public:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    string direction = "UDLR";
    void backtrack(vector<vector<int>> &mat, vector<string> &paths, int x, int y, string path)
    {
        int n = mat.size();
        if(x<0 || y<0 || x>=n || y>=n || mat[x][y]!=1)
            return;
        if(x==n-1 && y==n-1)
        {
            paths.push_back(path);
            return;
        }
        mat[x][y] = -1;
        for(int k=0; k<4; k++)
        {
            path.push_back(direction[k]);
            backtrack(mat, paths, x+dx[k], y+dy[k], path);
            path.pop_back();
        }
        mat[x][y] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        vector<string> paths;
        string path = "";
        backtrack(mat, paths, 0, 0, path);

        if(paths.size())
            return paths;
        return {"-1"};
    }
};
