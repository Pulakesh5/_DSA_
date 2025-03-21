class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==1)
            return arr[0];
        else if(n==2)
            return max(arr[0], arr[1]);
        vector<int> dp(n);;
        dp[0] = arr[0];
        dp[1] = max(arr[1], arr[0]);
        for(int i=2; i<n; i++)
        {
            dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
