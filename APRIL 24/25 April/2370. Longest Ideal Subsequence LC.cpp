class Solution {
public:
    int longestIdealString(string s, int k) {
        int len = s.size();
        vector<int> dp(len,1);
        vector<int> lastPos(26,-1);
        int ch, prev, next;
        for(int i=0; i<len; i++)
        {
            ch = s[i] - 'a';
            if(lastPos[ch]>=0)
                dp[i] = max(dp[lastPos[ch]]+1, dp[i]);
            prev = ch - 1;
            while(prev>=0)
            {
                if(lastPos[prev]>=0 && (ch-prev)<=k)
                    dp[i] = max(dp[lastPos[prev]]+1, dp[i]);
                prev--;
            }

            next = ch + 1;
            while(next<26)
            {
                if(lastPos[next]>=0 && (next-ch)<=k)
                    dp[i] = max(dp[lastPos[next]]+1, dp[i]);
                next++;
            }
            lastPos[ch] = i;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
