class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+5,0);
        long long point, next;
        for(int i=n-1;i>=0;i--)
        {
            next = i + questions[i][1] + 1;
            point = questions[i][0];
            dp[i] = 0ll + point + dp[min(1ll*n,next)];
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};
