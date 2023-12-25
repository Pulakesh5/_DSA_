class Solution {
public:
    int backtrack(string s, int i, vector<int> &dp)
    {
        int N = s.size();
        if(i>=N)
        {
            return 1;
        }
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        dp[i] = backtrack(s, i+1, dp);

        if(i+1<N)
        {
            if(s[i]=='1')
                dp[i] += backtrack(s, i+2, dp);
            else if(s[i]=='2')
            {
                if(s[i+1]<='6')
                    dp[i] += backtrack(s, i+2, dp);
                else
                    dp[i] += 0;
            }
        }
        return dp[i];
    }
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len, -1);
        return backtrack(s, 0, dp);
    }
};
