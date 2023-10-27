class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> dp(len+5, vector<int>(len+5,0));
        int pStart=0, pLen=1;
        for(int i=0; i<len; i++)
            dp[i][i] = 1;
        for(int i=0; i<(len-1); i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = 1;
                pStart=i;
                pLen=2;
            }
        }
            

        for(int l=2; l<len; l++)
        {
            for(int i=0; i<(len-l); i++)
            {
                if(s[i]==s[i+l] && dp[i+1][i+l-1]==1)
                {
                    dp[i][i+l] = 1;
                    pStart = i;
                    pLen = l+1;
                }
            }
        }
        
        return s.substr(pStart, pLen);
    }
};
