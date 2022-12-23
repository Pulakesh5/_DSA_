class Solution {
public:
    int maxCoins(int n, vector<int> &arr) {
        // code here
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        
        int maxi=INT_MIN, cost;
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j) continue;
                maxi=INT_MIN;
                for(int id=i;id<=j;id++)
                {
                    cost=arr[i-1]*arr[id]*arr[j+1]+dp[id+1][j]+dp[i][id-1];
                    maxi=max(cost,maxi);
                }
                dp[i][j]=maxi;
            }
        }
        
        return dp[1][n];
    }
};
