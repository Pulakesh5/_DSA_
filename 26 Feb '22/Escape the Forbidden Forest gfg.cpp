class Solution
{
    public:
    int dp[101][101];
    int build_bridges(string str1, string str2)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<101;i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }   
        return LCS(str1,str2, str1.length(), str2.length());
    }
    private:
    int LCS(string str1, string str2, int n1, int n2){
        // if(n1==0 || n2==0)
        //     return 0;
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
        if(str1[n1-1]==str2[n2-1])
            return dp[n1][n2]= 1 + LCS(str1,str2,n1-1,n2-1);
        
        return dp[n1][n2]=max(LCS(str1,str2,n1,n2-1), LCS(str1,str2,n1-1,n2));
    }
    
};
