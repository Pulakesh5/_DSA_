class Solution {
public:
    int solve(int l, int r, int m, vector<int> &pref_sum, vector<vector<int>> &dp){
        if(l>r)
            0;
        if(l==r)
            return 1;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int l_sum, r_sum, l_val, r_val;
        int maxSplit = INT_MIN;
        for(int i=l; i<r; i++)
        {
            l_sum = pref_sum[i]-pref_sum[l-1];
            r_sum = pref_sum[r]-pref_sum[i];
            
            if((i-l==0||l_sum>=m)  && (r-i==1 || r_sum>=m))
            {
                l_val = solve(l, i, m, pref_sum, dp);
                r_val = solve(i+1, r, m, pref_sum, dp);
                if(l_val==INT_MAX || r_val==INT_MAX)
                    continue;
                maxSplit = max(maxSplit, l_val+r_val);
            }
        }
        return dp[l][r] = (maxSplit == INT_MIN ? INT_MAX : maxSplit);
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int len = nums.size();
        vector<int> pref_sum(len+1,0);
        vector<vector<int>> dp(len+1,vector<int>(len+1,-1));

        for(int i=0; i<len; i++)
            pref_sum[i+1]+=(pref_sum[i]+nums[i]);
        
        return solve(1, len, m, pref_sum, dp) == len;
    }
};
