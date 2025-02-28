class Solution {
public:

    string shortestCommonSupersequence(string a, string b) {
        string superSeq = "";
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n+2, vector<int>(m+2,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i] == b[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else 
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        // return dp[n][m];
        // cout<<LCS<<endl;
        int i=n, j=m;
        while(i && j)
        {
            if(a[i-1] == b[j-1])
            {
                superSeq.push_back(a[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                    superSeq.push_back(a[--i]);
                else
                    superSeq.push_back(b[--j]);
            }
        }

        while(i)
            superSeq.push_back(a[--i]);
        
        while(j)
            superSeq.push_back(b[--j]);
        
        reverse(superSeq.begin(), superSeq.end());
        return superSeq;
    }
};
