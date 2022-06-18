class Solution {
public:
    bool check(vector<vector<int>> matrix, int x, int y){
        int row=matrix.size(), col=matrix[0].size();
        return x>=0 && y>=0 && x<row && y<col && matrix[x][y]==1;
    }
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int xs, int ys, int xd, int yd){
        if(!check(matrix,xs,ys)) return INT_MIN;
        //if(dp[xs][ys]!=-1) return dp[xs][ys];
        if(xs==xd && ys==yd) return 0;//dp[xs][ys]=0;
        
        matrix[xs][ys]=0;
        int up=dfs(matrix, dp, xs, ys-1, xd, yd);
        int down=dfs(matrix, dp, xs, ys+1, xd, yd);
        int left=dfs(matrix, dp, xs-1, ys, xd, yd);
        int right=dfs(matrix, dp, xs+1, ys, xd, yd);
        matrix[xs][ys]=1;
        
        return 1+max({up,down,left, right});
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int row=matrix.size(), col=matrix[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,-1));
        int ans=dfs(matrix, dp, xs, ys, xd, yd);
        return ans <0 ? -1: ans;
    }
};
