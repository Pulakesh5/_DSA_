class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<int> count(sum+1, 0);
        int N = coins.size();
        count[0] = 1;
        for(int i=0; i<N; i++)
        {
            for(int coin = coins[i]; coin<=sum; coin++)
                count[coin] += count[coin-coins[i]];
        }
        return count[sum];
    }
};
