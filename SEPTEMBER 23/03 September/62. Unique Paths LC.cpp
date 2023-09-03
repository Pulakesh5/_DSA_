class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> uniquePath(m+1, vector<int>(n+1,0));
        uniquePath[m][n] = 1;
        for(int i=m; i>0; i--)
        {
            for(int j=n; j>0; j--)
            {
                if(j-1>0)
                    uniquePath[i][j-1]+=uniquePath[i][j];
                if(i-1>0)   
                    uniquePath[i-1][j]+=uniquePath[i][j];
            }
        }
        return uniquePath[1][1];
    }
};
