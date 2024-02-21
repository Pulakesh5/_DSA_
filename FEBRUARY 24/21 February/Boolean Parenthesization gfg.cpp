class Solution{
public:
    int dp[205][205][2];
    int MOD = 1003;
    int f(int i, int j, int TF, string &s)
    {
        if(i==j)
        {
            if((s[i]=='T' && TF==0) || (s[i]=='F' && TF==1))
                return 1;
            else
                return 0;
        }
        if(dp[i][j][TF]!=-1)
            return dp[i][j][TF];
        int count=0;
        for(int idx=i+1; idx<j; idx+=2)
        {
            int lTrue = f(i,idx-1,0,s), rTrue = f(idx+1, j, 0, s);
            int lFalse = f(i,idx-1,1,s), rFalse = f(idx+1, j, 1, s);
            
            if(s[idx]=='&')
            {
                if(TF==0)
                    count = (count + lTrue*rTrue)%MOD;
                else
                    count = (count + (lTrue*rFalse)%MOD + lFalse*rTrue + lFalse*rFalse)%MOD;
            }
            else if(s[idx]=='|')
            {
                if(TF==1)
                    count = (count + lFalse*rFalse)%MOD;
                else
                    count = (count + (lTrue*rFalse)%MOD + lFalse*rTrue + lTrue*rTrue)%MOD;

            }
            else
            {
                if(TF==0)
                    count = (count + lTrue*rFalse + lFalse*rTrue)%MOD;
                else
                    count = (count + lTrue*rTrue + lFalse*rFalse)%MOD;
            }
        }
        return dp[i][j][TF] = count;
    }
    int countWays(int n, string s){
        // code here
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,0,s);
    }
};
