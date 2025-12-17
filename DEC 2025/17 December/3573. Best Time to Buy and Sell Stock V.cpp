class Solution {
public:
    long long dp[1005][505][3];
    const long long MIN = -1e14;
    // // const long long MIN = INT_MIN;
    // long long solve(vector<int> prices, int index, int k, int transactionType) {
    //     int n = prices.size();
    //     if(index==n) { // reached end of array
    //         if(k>=0 && transactionType==0) // no unfinished transaction
    //             return 0;
    //         return MIN; // if there is unfinished transaction
    //     }

    //     if(dp[index][k][transactionType]!=MIN)
    //         return dp[index][k][transactionType];

    //     int take = MIN, not_take = MIN;
    //     if(k>0) { // possible transactions remaining
    //         if(transactionType == 0) { // no running transaction, let's start one
    //             take = max(solve(prices, index+1, k, 1) - prices[index], //buy position
    //                         solve(prices, index+1, k, 2) + prices[index]); // sell position
    //         } else if(transactionType == 1) { // buy position running, close here
    //             take = (solve(prices, index+1, k-1, 0)+prices[index]);
    //         } else { // sell position running, close here
    //             take = (solve(prices, index+1, k-1, 0)-prices[index]);
    //         }
    //     }

    //     not_take = solve(prices, index+1, k, transactionType); // continue previous running state
    //     // cout<<"Index "<<index<<" k "<<k<<" transaction "<<transactionType<<" : take= "<<take<<" "<<" not_take= "<<not_take<<endl;
    //     return dp[index][k][transactionType] = max(take, not_take);
    // }
    
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        for(int i=0; i<=n; i++)
            for(int j=0; j<=k; j++)
                for(int p=0; p<3; p++)
                    dp[i][j][p] = MIN;
        // return solve(prices, 0, k, 0);

        for(int j=0; j<=k; j++)
            dp[n][j][0] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=k; j++) {
                dp[i][j][0] = dp[i+1][j][0]; // no transaction
                dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][1]-prices[i]); // buy position started at pos i
                dp[i][j][0] = max(dp[i][j][0], dp[i+1][j][2]+prices[i]); // shortsell position started at pos i

                dp[i][j][1] = dp[i+1][j][1];
                dp[i][j][2] = dp[i+1][j][2];

                if(j>0) {
                    dp[i][j][1] = max(dp[i+1][j][1], dp[i+1][j-1][0]+prices[i]); // continuing buy position from here max(not selling, selling) 
                    dp[i][j][2] = max(dp[i+1][j][2], dp[i+1][j-1][0]-prices[i]); // continuing sell position from here max(not buying, buying)
                }
            }
        }
        return dp[0][k][0];
    }
};
