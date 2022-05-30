class Solution {
public:
    //vector<vector<int>> dp(101,vector<int>(101,-1));
    int dp[101][101];
    int solve(int i,int j, int prev, vector<vector<int>> &matrix){
        int n=matrix.size(),m=matrix[0].size();
        if(i<0 || i>=n || j<0 || j>=m || prev>=matrix[i][j]) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int curr=matrix[i][j];
        return dp[i][j]=max({solve(i+1,j,curr,matrix),
                             solve(i-1,j,curr,matrix),
                             solve(i,j+1,curr,matrix),
                             solve(i,j-1,curr,matrix)}
                             )+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                dp[i][j]=-1;
        int n=matrix.size(), m= matrix[0].size();
        int ans=-1,temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp = solve(i,j,0,matrix);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};
