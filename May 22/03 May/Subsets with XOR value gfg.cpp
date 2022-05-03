// 0/1 Knapsack Problem 

class Solution{
public:
    int rec(int i, int xr, int n, int k,vector<int> arr,  vector<vector<int>> &dp){
        if(i==n) return xr==k;
        
        if(dp[i][xr]!=-1) return dp[i][xr];
        
        int taken= rec(i+1,xr^arr[i],n,k,arr,dp);
        
        int not_taken= rec(i+1,xr,n,k,arr,dp);
        
        return dp[i][xr]=taken+not_taken;
    }
    
    int subsetXOR(vector<int> arr, int n, int k) {
        vector<vector<int>> dp(n, vector<int> (129,-1));
        int i=0,xr=0;
        return rec(0,0,n,k,arr,dp);
    }

};
