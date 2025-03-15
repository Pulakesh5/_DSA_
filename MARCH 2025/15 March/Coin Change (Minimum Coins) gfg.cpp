class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        vector<int> count(sum+5, INT_MAX);
        int N = coins.size();
        count[0] = 0;
        for(int i=0; i<N; i++)
        {
            for(int amount = coins[i]; amount<=sum; amount++)
            {
                if(count[amount-coins[i]] != INT_MAX)
                    count[amount] = min(count[amount], count[amount-coins[i]]+1);
            }
        }
        return count[sum] == INT_MAX? -1: count[sum];
    }
};
