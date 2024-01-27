class Solution{
private:
    vector<vector<int>> dp, val;
    int n;

public:
    int MCM(int i, int j, int arr[]){
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int tmp = arr[i-1] * arr[k] * arr[j] + MCM(i, k, arr) + MCM(k+1, j, arr);
            if(tmp < ans) ans = tmp, val[i][j] = k; 
        }
        return dp[i][j] = ans;
    }
    void construct_string(int i, int j, string &ans){
        if(i > j) return; 
        if(i == j){
            ans.push_back('A' + i - 1);
            return;
        }
        ans.push_back('('); 
        construct_string(i, val[i][j], ans); 
        construct_string(val[i][j] + 1, j, ans);
        ans.push_back(')'); 
        return;
    }
    string matrixChainOrder(int p[], int N){
        // code here
        n = N;
        dp.resize(n, vector<int>(n, -1));
        val.resize(n, vector<int>(n, -1));
        MCM(1, n-1, p);
        string ans = ""; 
        construct_string(1, n-1, ans);  
        return ans;
    }
};
