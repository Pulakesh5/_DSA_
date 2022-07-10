class Solution
{
public:
    vector<vector<int>> ans;
    int dx[2]={1,0},dy[2]={0,1};
    void backtrack(vector<vector<int>> &grid, int a, int b, vector<int> &path){
        int n=grid.size(), m=grid[0].size();
        if(a==(n-1) && b==(m-1)){
            ans.push_back(path);
            return;
        }
        //path.push_back(grid[a][b]);
        for(int i=0;i<2;i++){
            if((a+dx[i])<n && (b+dy[i])<m){
                path.push_back(grid[a+dx[i]][b+dy[i]]);
                backtrack(grid,a+dx[i],b+dy[i],path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<int> path;
        path.push_back(grid[0][0]);
        backtrack(grid,0,0,path);
        return ans;
    }
};
