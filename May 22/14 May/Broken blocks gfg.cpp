class Solution {
    
public:
int row, column;
int rec(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(r<0||r>=row||c<0||c>=column||matrix[r][c]==-1) return 0;
    if(r==row-1) return matrix[r][c];
    if(dp[r][c]!=-2) return dp[r][c];
    
    int top = rec(r+1,c,matrix, dp);
    int left=rec(r+1,c-1,matrix,dp);
    int right=rec(r+1,c+1, matrix, dp);
    
    return dp[r][c]=matrix[r][c]+max({left,top,right});
}

int MaxGold(vector<vector<int>>&matrix){
    row=matrix.size();
    column=matrix[0].size();
    int r=row,c=column;
    vector<vector<int>> dp(row,vector<int>(column,-2));
    int ans=INT_MIN;
    for(int i=0;i<column;i++){
        //vector<vector<int>> dp(row,vector<int>(column,-2));
        ans = max(ans,rec(0,i,matrix,dp));
    }
    return ans;
}
};
