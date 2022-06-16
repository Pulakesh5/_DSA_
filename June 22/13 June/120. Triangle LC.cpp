class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(200,vector<int>(200,-1));
        int level=0,pos=0,path;
        return dfs(dp,triangle,level,pos);
    }
    
    int dfs(vector<vector<int>>&dp, vector<vector<int>>&triangle, int level, int pos){
        if(level>=triangle.size()) return 0;
        if(dp[level][pos]!=-1) return dp[level][pos];
        
        return dp[level][pos]=triangle[level][pos] + min(dfs(dp,triangle,level+1,pos),dfs(dp,triangle,level+1,pos+1));
    }
};
