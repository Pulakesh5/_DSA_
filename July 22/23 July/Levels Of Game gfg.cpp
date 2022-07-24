class Solution{
    public:
        int recursion(int h,int m, bool flag, vector<vector<int>> &dp){
            if(h<=0 || m<=0) return 0;
            if(dp[h][m]!=-1) return  dp[h][m];
            
            return dp[h][m] = 1 + (flag ? recursion(h+3,m+2,false,dp) : 
            max(recursion(h-5,m-10,true,dp), recursion(h-20,m+5,true,dp)));
        }
        
        int maxLevel(int h,int m)
        {
            // code here
            int n=2001;
            vector<vector<int>> dp(n,vector<int>(n,-1));
            return recursion(h,m,true,dp)-1;
        }
};
