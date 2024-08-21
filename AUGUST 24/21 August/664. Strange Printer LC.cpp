class Solution {
public:
    int strangePrinter(string s) {
        int len = s.size();
        if(len==1)
            return 1;
        else if(len==2)
        {
            return 1+(s[0]!=s[1]);
        }
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i=0; i<len; i++)
            dp[i][i] = 1;
        
        for(int i=len-1; i>=0; i--)
        {
            for(int dist=1; dist+i<len; dist++)
            {
                
                if(dist==1)
                {
                    dp[i][i+1] = 1+(s[i]!=s[i+1]);
                    continue;
                }
                int j=dist+i;
                dp[i][j] = INT_MAX;
                for(int k=i; k+1<=j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
                dp[i][j]-=(s[i]==s[j]);
            }
        }
        return dp[0][len-1];
    }
};
