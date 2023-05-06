    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        int dp[1005][105]; // dp[i][j] => 1 if it is possible to make a change of amount i with exactly j coins
        memset(dp,0,sizeof(dp));
        sort(coins.begin(), coins.end());
        dp[0][0]=1;
        for(int amount=1;amount<=target;amount++)
        {
            for(int count=1;count<=K;count++)
            {
                for(int coin:coins)
                {
                    if(coin>amount)
                        break;
                    if(dp[amount-coin][count-1]==1)
                        dp[amount][count]=1;
                }
            }
        }
        return dp[target][K];
    }
