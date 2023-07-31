class Solution {
public:
    //(101,vector<int>(101,-1));
    vector<vector<int>> dp;
    int count(string s, int start, int end, vector<vector<int>> &dp)
    {
        if(start>end)   
            return 0;
        if(dp[start][end] != -1)
            return dp[start][end];
        if(start==end)
            return 1; //dp[start][end] = 1;
        int minCuts = 1e9;
        if(s[start]==s[end] || s[end-1]==s[end])
            minCuts = count(s, start, end-1, dp);
        else if(s[start]==s[start+1])
            minCuts = count(s, start+1, end, dp);
        else
        {
            minCuts = count(s, start, end-1, dp) + 1;
            for(int i=start+1; i<end; i++)
            {
                if(s[i] == s[end])
                    minCuts = min(minCuts, (count(s,start,i-1, dp) + count(s, i, end-1, dp)));
            }
        }
        
        // if(s[start]==s[end])
        //     dp[start][end] = minCuts - 1;
        // else
        //     dp[start][end] = minCuts;
        return dp[start][end] = minCuts;
    }
    int strangePrinter(string s) {
        int len = s.size();
        // cout<<len<<endl;
        dp.resize(len+1, vector<int>(len+1,-1));
        return count(s, 0, len-1, dp);
    }
};
