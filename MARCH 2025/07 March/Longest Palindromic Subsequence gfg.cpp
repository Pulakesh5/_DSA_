class Solution {
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string rev(s.rbegin(), s.rend());
        // cout<<s<<" "<<rev<<endl;
        int N = s.size();
        vector<vector<int>> cs(N+1, vector<int>(N+1));
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(s[i-1] == rev[j-1])
                    cs[i][j] = cs[i-1][j-1]+1;
                else
                    cs[i][j] = max(cs[i-1][j], cs[i][j-1]);
            }
        }
        return cs[N][N];
    }
};
