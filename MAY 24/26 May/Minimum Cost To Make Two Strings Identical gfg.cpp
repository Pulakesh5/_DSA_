class Solution {
  public:
    int commonSubseq(string x, string y)
    {
        int lenX = x.size();
        int lenY = y.size();
        vector<vector<int>> dp(lenX+1,vector<int>(lenY+1,0));
        for(int i=1; i<=lenX; i++)
        {
            for(int j=1; j<=lenY; j++)
            {
                if(x[i-1]==y[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[lenX][lenY];
    }
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int lenX = x.size();
        int lenY = y.size();
        int commonLen = commonSubseq(x, y);
        return ((lenX-commonLen)*costX + (lenY-commonLen)*costY);
    }
};
