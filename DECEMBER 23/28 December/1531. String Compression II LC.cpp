class Solution {
public:
    int countDigit(int num)
    {
        if(num==1)
            return 0;
        else if(num<10)
            return 1;
        else if(num<100)
            return 2;
        return 3;
    }
    int fun(string s, int pos, int k, vector<vector<int>> &dp)
    {
        int len = s.size();
        if(k<0)
            return len;
        
        if(pos>=len || (len-pos)<=k)
            return 0;
        
        if(dp[pos][k]!=-1)
            return dp[pos][k];
        
        vector<int> count(26,0);
        int mostOccuring=0, result=INT_MAX;

        for(int i=pos; i<len; i++)
        {
            mostOccuring = max(mostOccuring, ++count[s[i]-'a']);
            result = min(result, 1+countDigit(mostOccuring)+fun(s, i+1, k-(i-pos+1-mostOccuring), dp));
        }
        return dp[pos][k] = result;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int len = s.size();
        vector<vector<int>> dp(len+5, vector<int>(k+5,-1));
        return fun(s,0,k,dp);
    }
};
