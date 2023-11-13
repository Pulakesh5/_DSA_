class Solution
{
    public:
     int lcs(int i,int j,string&x,string&y,vector<vector<int>>&dp){
        if(i<0||j<0)
        return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(x[i]==y[j])
        return dp[i][j]=1+lcs(i-1,j-1,x,y,dp);
        return dp[i][j]=max(lcs(i-1,j,x,y,dp),lcs(i,j-1,x,y,dp));
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>>dp(X.length(),vector<int>(Y.length(),-1));
        int ans=lcs(X.length()-1,Y.length()-1,X,Y,dp);
        return X.length()+Y.length()-ans;
    }
};
