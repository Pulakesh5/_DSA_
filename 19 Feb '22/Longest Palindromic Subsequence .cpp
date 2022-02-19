//Author : Neel
int solve(string s) {
     string rs=s;
    reverse(rs.begin(),rs.end());
    int dp[s.size()+1][s.size()+1];
    memset(dp,0,sizeof(dp));
    /*
    for(int i=0;i<s.size()+1;i++)
    {
        for(int j=0;j<s.size()+1;j++)
        {
            dp[i][j]=0;
        }
    }
    */
    for(int i=1;i<s.size()+1;i++)
    {
        for(int j=1;j<s.size()+1;j++)
        {
            if(rs[i-1]==s[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }


        }
    }
    cout<<rs<<endl;
    cout<<s<<endl;
    /*
    for(int i=0;i<s.size()+1;i++)
    {
        for(int j=0;j<s.size()+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return dp[s.size()][s.size()];
}
