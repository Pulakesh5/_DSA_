class Solution {
public:
    int dp[102][102][102]; 
    // dp[i][j][k] = No of subsets upto i indexed group, with j memebers and atleast k profit
    long mod = 1e9+7;
    int solve(int i, int j, int k, int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        if(i==profit.size())
        {
            if(j<=n && k>=minProfit) return 1;
            return 0;
        }
        else if(j>n)
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        int take = solve(i+1,j+group[i],min(minProfit,k+profit[i]),n,minProfit,group,profit);

        int not_take = solve(i+1,j,k,n,minProfit,group,profit);

        return dp[i][j][k] = (take%mod + not_take%mod)%mod;
    } 



    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,minProfit,group,profit);
    }
};
