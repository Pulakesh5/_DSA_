class Solution {
public:
    vector<int> dp;

    int integerBreak(int n) {
        if(dp.size()==0)
            dp.resize(60,-1);
        if(n<=2)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        int maxProduct = 1;
        for(int i=1; i<n; i++)
        {
            maxProduct = max(maxProduct, max(integerBreak(i), i) * max(integerBreak(n-i), n-i));
        }
        return dp[n] = maxProduct;
        // int first = n/2;
        // int second = n-n/2;
        // return max(integerBreak(first), first) * max(integerBreak(second),second);
    }
};
