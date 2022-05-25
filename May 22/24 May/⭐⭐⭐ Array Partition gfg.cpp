class Solution{
    public:
    bool helper(int ind, int k, int m, vector<int>& A, vector<int>& dp){
        bool flag = false;
        if(ind <= -1) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind - k + 1; i >= 0 && A[ind] - A[i] <= m; i--){
            flag = flag | helper(i - 1, k, m, A, dp);
            if(flag == true){
                break;
            }
        }
        dp[ind] = flag ? 1 : 0;
        return flag;
    }
    bool partitionArray(int N, int K, int M, vector<int> &A){
        sort(A.begin(), A.end());
        vector<int> dp(N, -1);
        helper(N - 1, K, M, A, dp);
        return dp[N - 1];
    }
};
