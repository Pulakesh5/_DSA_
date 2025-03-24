class Solution {
  public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int mn = INT_MAX;
        for(int k=i; k<=j-1; k++)
        {
            int tmp = solve(arr, i, k, dp) + solve(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
            mn = min(mn, tmp);
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i=1, j=n-1;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(arr, i, j, dp);
    }
};
