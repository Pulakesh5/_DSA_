class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, long long> dp;
        for(int num:arr)
            dp[num] = 1;
        set<int> uniques(arr.begin(), arr.end());
        long long MOD = 1e9+7;
        for(int num:uniques)
        {
            for(int div=2; div<=sqrt(num); div++)
            {
                if((num%div)==0 && uniques.find(div)!=uniques.end() && uniques.find(num/div)!=uniques.end())
                {
                    if(div == (num/div))
                        dp[num] += (dp[div]*dp[div])%MOD;
                    else
                        dp[num] += (2ll*dp[div]*dp[num/div])%MOD;
                }
            }
            cout<<num<<" : "<<dp[num]<<endl;
        }
        int countTrees = 0;
        for(int num:arr)
        {
            // cout<<dp[num]<<endl;
            countTrees = (countTrees + dp[num])%MOD;
        }
        return countTrees;
    }
};
