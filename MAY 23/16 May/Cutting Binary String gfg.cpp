    bool isPowerFive(string &s, int i, int j)
    {
        long long num = 0;
        
        for(int k=i;k<=j;k++)
            num = num * 2 + (s[k]-'0');
        
        while(num>1)
        {
            if(num%5 > 0)
                return false;
            num/=5;
        }

        return true;
    }
    int cuts(string s){
        int len = s.length();
        vector<vector<int>> dp(len+1,vector<int>(len+1,len));
        long long num = 0;
        
        dp[len][len-1] = 0;
        
        for(int j=len-1;j>=0;j--)
        {
            num = 0;
            for(int i=j;i>=0;i--)
            {
                // num = num * 2 + (s[i] - '0');
                if(s[i]!='0' && dp[j+1][len-1]!=INT_MAX &&  isPowerFive(s,i,j))
                    dp[i][len-1] = min(dp[i][len-1], 1 + dp[j+1][len-1]);
                else if(dp[i][len-1] == len)
                    dp[i][len-1] = INT_MAX;
                // cout<<i<<" , "<<j<<" : "<<dp[i][len-1]<<"\n";
            }
            // cout<<endl;
        }
        if(dp[0][len-1] == INT_MAX)
            return -1;
        return dp[0][len-1];
    }
