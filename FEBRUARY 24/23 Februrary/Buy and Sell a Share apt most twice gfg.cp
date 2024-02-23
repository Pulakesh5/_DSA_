class Solution
{
    public:
        //User function Template for C++
        int dp[100001][2][2];
        int find(vector<int> &price, int i, int t, int k)
        {
            if(k==0 || i>=price.size())
                return 0;
            if(dp[i][t][k]!=-1)
                return dp[i][t][k];
            if(t)
            {
                return dp[i][t][k] = max(-price[i]+find(price,i+1,0,k), find(price,i+1,1,k));
            }
            else
            {
                return dp[i][t][k] = max(price[i]+find(price,i+1,1,k-1), find(price,i+1,0,k));
            }
        }
        int maxProfit(vector<int>&price){
            //Write your code here..
            memset(dp,-1,sizeof(dp));
            return find(price,0,1,2);
        }
};
