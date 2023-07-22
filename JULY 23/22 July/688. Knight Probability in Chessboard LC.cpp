class Solution {
public:
    double dp[26][26][101];
    const int dx[8] = {-1,-1,1,1,-2,-2,2,2};
    const int dy[8] = {2,-2,2,-2,1,-1,1,-1};
    double knightProbability(int n, int k, int row, int column) 
    {
        memset(dp,0,sizeof(dp));
        dp[row][column][k] = 1.0;
        double prob = 1.0/8.0;
        int nx, ny;
        for(int move=k; move>0; move--)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(dp[i][j][move])
                    {
                        for(int c=0; c<8; c++)
                        {
                            nx = i + dx[c];
                            ny = j + dy[c];
                            if(nx>=0 && ny>=0 && nx<n && ny<n)
                                dp[nx][ny][move-1] += prob*dp[i][j][move];
                        }
                    }
                }
            }
        }
        double finalProb = 0.0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dp[i][j][0]>0.0)
                    finalProb += dp[i][j][0];
            }
        }

        return finalProb;
    }
};
