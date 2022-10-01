class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        dp[n]=1;
        int pos=0;
        return s.empty() ? 0 : numDecode(pos,s,dp);
    }
    
    int numDecode(int pos, string s, vector<int> &dp)
    {
        if(dp[pos]>-1) return dp[pos];
        if(s[pos]=='0') return dp[pos]=0;
        int res=numDecode(pos+1,s,dp);
        if((pos+1)<s.size() && (s[pos]=='1' || (s[pos]=='2'&& s[pos+1]<'7'))) res+=numDecode(pos+2,s,dp);
        return dp[pos]=res;
    }
};
