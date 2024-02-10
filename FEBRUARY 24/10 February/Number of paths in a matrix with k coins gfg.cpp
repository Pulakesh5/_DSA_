long long  dp[101][101][101];
    long long solve(int k, int row, int col, vector<vector<int>> &arr, int n, int sum)
    {
        if(row>=n || row < 0)
            return 0;
        if(col >=n || col < 0)
            return 0;
        
        if(sum > k)
            return 0;
        sum = sum + arr[row][col];
        if(dp[row][col][sum] != -1)
        {
            return dp[row][col][sum];
        }
        long long  ans = 0;
        if(k == sum and row == n-1 and col == n-1)
        {
            return dp[row][col][sum]=1;
           // return 1;
        }
        else
        {
            ans = ans + solve(k,row+1,col,arr,n,sum);
            ans += solve(k,row,col+1,arr,n,sum);
        }
        return dp[row][col][sum]=ans;
        //return ans;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr)
    {
        //dp = vector<vector<int>>(n,vector<int>(n,-1)); 
        memset(dp,-1,sizeof(dp));
        return solve(k,0,0,arr,n,0);
        // Code Here
    }
