class Solution {
public:
    int schedule(vector<int> &diff, vector<vector<int>> &dp, int i, int d)
    {
        int maxDiff=0, len = diff.size(), cost=INT_MAX;
        if(dp[i][d]!=-1)    
            return dp[i][d];
        if(d==0)
        {
            for(int j=i; j<len; j++)
                maxDiff=max(maxDiff, diff[j]);
            return dp[i][d] = maxDiff;
        }
        else
        {
            for(int j=i; j<(len-d); j++)
            {
                maxDiff = max(maxDiff, diff[j]);
                cost = min(cost, maxDiff + schedule(diff, dp, j+1, d-1));
            }
            return dp[i][d] = cost;
        }
    }
    // 1 | 2 3 4 5
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if(d>len)
            return -1;
        vector<vector<int>> dp(len+2,vector<int>(d+2,-1));
        return schedule(jobDifficulty, dp, 0, d-1);
    }
};
