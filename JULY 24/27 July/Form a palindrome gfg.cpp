class Solution{
  public:
    int lcs(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                if (s[idx1 - 1] == t[idx2 - 1])
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                else
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
            }
        }
        return dp[n][m];
    }
    int countMin(string str){
    //complete the function here
        string t = str;
        reverse(t.begin(), t.end());
        int res = lcs(str, t);
        // The minimum number of insertions is the length of the string minus the LCS length
        return str.size() - res;
    }
};
