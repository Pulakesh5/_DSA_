class Solution{
public:
    int numberSequence(int m, int n){
        // code here
        vector<vector<long long>> dp(n+5,vector<long long>(m+5,0));
        // dp[i][j] => #seq of length i, ending with j
        for(int i=1; i<=m; i++)
            dp[0][i] = 1;
        for(int i=0; i<(n-1); i++)
        {
            for(int j=1; j<=(m/2); j++)
            {
                for(int k=2*j; k<=m; k++)
                    dp[i+1][k]+=dp[i][j];
            }
        }
        long long countOfSeq=0;
        for(int i=1;i<=m; i++)
            countOfSeq+=dp[n-1][i];
        return countOfSeq;
    }
};
