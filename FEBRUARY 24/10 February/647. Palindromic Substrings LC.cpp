class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int dp[n][n];
        bool p[n][n];
        memset(p,false,sizeof(p));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            p[i][i]=true;
            dp[i][i]=1;
        }
            
        for(int i=0;i<(n-1);i++)
        {
            if(s[i]==s[i+1])
            {
                p[i][i+1]=true;
                dp[i][i+1]=2;
            }
        }
        int j;
        for(int gap=1;gap<n;gap++){
            for(int i=0;i<(n-gap);i++){
                j=i+gap;
                if(s[i]==s[j] && p[i+1][j-1])
                    p[i][j]=true;
                
                dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
                dp[i][j]+=p[i][j];
            }
        }
        return dp[0][n-1];
    }
};
