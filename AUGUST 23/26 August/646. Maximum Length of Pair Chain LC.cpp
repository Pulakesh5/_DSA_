class Solution {

public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int len = pairs.size();
        vector<int> dp(len,1);
        int maxChain = 1;
        for(int i=1; i<len; i++)
        {
            // cout<<pairs[i][0]<<" ,"<<pairs[i][1]<<endl;
            for(int j=i-1; j>=0; j--)
            {
                if(pairs[j][1]<pairs[i][0])
                {
                    // cout<<i<<" ";
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            // cout<<endl;
            maxChain = max(maxChain, dp[i]);
        }
        return maxChain;
    }
};
