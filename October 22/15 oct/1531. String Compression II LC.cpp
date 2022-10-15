class Solution {
public:
    const static int N=127;
    
    int dp[N][N];
    string str;
    int len;
    int countdigit(int n)
    {
        return (n==1?0:(n<10?1:(n<100?2:3)));        
    }

    int rec(int pos, int k)
    {
        if(k<0) return N;
        
        if(pos>=len || len-pos<=k) return 0;
        
        if(dp[pos][k]!=-1) return dp[pos][k];
        
        int count[26]={0};
        int res=N;
        for(int i=pos,most=0;i<len;i++)
        {
            most=max(most,++count[str[i]-'a']);
            res=min(res,1+countdigit(most)+rec(i+1,k-(i-pos+1-most)));
        }
        
        return dp[pos][k]=res;
        
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        str=s;
        len=s.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,k);
    }
};
