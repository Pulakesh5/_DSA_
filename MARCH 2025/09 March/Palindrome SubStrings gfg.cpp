class Solution {
  public:
    int countPS(string &s) {
        // code here
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N,0));
        for(int i=0; i<N; i++)
        {
            dp[i][i] = 1;
        }
        int count = 0;
        for(int len=2; len<=N; len++)
        {
            for(int i=0; i<(N-len+1); i++)
            {
                int j = i+len-1;
                if(s[i] == s[j])
                {
                    if(len==2)
                        dp[i][j] = 2;
                    else if(dp[i+1][j-1])
                        dp[i][j] += 2+dp[i+1][j-1];
                    else 
                        dp[i][j] = 0;
                }
                count += (dp[i][j]>=2);
            }
        }
        return count;
    }
};
