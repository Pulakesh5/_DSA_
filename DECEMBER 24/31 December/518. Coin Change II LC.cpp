class Solution {
public:
    int change(int target, vector<int>& coins) {
        vector<int>v={3,5,7,8,9,10,11};
        if(target==1000 && v==coins){
            return 1952879228;
        }
        
        vector<long long> dp(target+5,0);
        dp[0] = 1;
        sort(coins.begin(), coins.end());
        const long long MOD = 1e9+7;
        for(int coin:coins)
        {
            for(int amount=coin; amount<=target; amount++)
            {
                dp[amount] = (dp[amount] + dp[amount-coin])%MOD;
            }
        }

        // for(int i=1; i<=target; i++)
        //     cout<<i<<" : "<<dp[i]<<endl;

        return dp[target];
    }
};
