static int MOD = 1e9+7;
class Solution {
public:
    
    int arrLen;
    int rec(vector<vector<int>> &dp, int index, int steps)
    {
        if(index==0 && steps==0)
            return 1;
        if(index<0 || index>=arrLen || steps==0 || index>steps)
            return 0;
        if(dp[index][steps] != -1)
            return dp[index][steps];
        return dp[index][steps] = ( ( rec(dp, index-1, steps-1) + rec(dp, index+1, steps-1) )%MOD
                + rec(dp, index, steps-1) )%MOD;
    }
    int numWays(int steps, int arrLen) {
        // total number of right and left steps should be equal
        this->arrLen = arrLen;
        vector<vector<int>> dp(steps/2+1, vector<int> (steps+1, -1));
        return rec(dp, 0, steps);
    }
};
