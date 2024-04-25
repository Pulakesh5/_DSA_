class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        vector<vector<int>> pre(n,vector<int>(m+1,0));
        for(int i=0; i<n; i++)
            pre[i][1] = mat[i][0];
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                pre[i][j+1]=pre[i][j]+mat[i][j];
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=1; j<=m; j++)
        //         cout<<pre[i][j]<<" ";
        //     cout<<endl;
        // }
        int maxSumHourglass = -1;
        int upper, t, lower;
        for(int i=2; i<n; i++)
        {
            for(int j=2; j<m; j++)
            {
                // cout<<i<<" "<<j<<endl;
                upper = (pre[i-2][j+1]-pre[i-2][j-2]);
                t = mat[i-1][j-1];
                lower = (pre[i][j+1]-pre[i][j-2]);
                // cout<<upper<<" "<<t<<" "<<lower<<endl;
                maxSumHourglass = max(maxSumHourglass, upper+t+lower);
            }
        }
        return maxSumHourglass;
    }
};
