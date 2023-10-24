
class Solution{
public:
    int palindromicPartition(string s)
    {
        // code here
        int n=s.length();
        vector<vector<bool>>isPalindrome(n+1,vector<bool>(n+1,0));
        for(int i=0;i<n;i++)
        {
            isPalindrome[i][i]=1;
        }
        for(int gap=1;gap<n;gap++)
        {
            for(int i=0;i<n-gap;i++)
            {
                int j=i+gap;
                if(gap==1)
                {
                    if(s[i]==s[j])
                    isPalindrome[i][j]=1;
                }
                else
                {
                    if((isPalindrome[i+1][j-1]==1) && s[i]==s[j])
                    isPalindrome[i][j]=1;
                }
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int j=0;j<n;j++)
        {
            if(isPalindrome[j][n-1]==0)
            dp[n-1][j]=0x3f3f3f3f;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j];
                if(isPalindrome[j][i] && i>=j)
                {
                    dp[i][j]=min(dp[i][j],1+dp[i+1][i+1]);
                }
            }
        }
        return dp[0][0];
    }
};
