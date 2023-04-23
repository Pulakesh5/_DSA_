class Solution {
public:
    long long mod=1e9+7;
    int rec(int pos, string &s, int k, long long dp[])
    {
        int len = s.length();
        if(pos>=len)
            return 1;
        if(dp[pos]!=-1)
            return dp[pos];
        long long num=0, count=0;

        for(int i=pos;i<len;i++)
        {
            num=num*10+(s[i]-'0');
            if(num<=k  && num>0)
            {
                count = (count + rec(i+1,s,k,dp))%mod;
                
            }
            else
                break;
        }
        return dp[pos] = count;

    }
    int numberOfArrays(string s, int k) {
        int len=s.length();
        long long dp[len+1];
        memset(dp,-1,sizeof(dp));
        rec(0,s,k,dp);
        return dp[0];
    }
};
