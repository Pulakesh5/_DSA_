    vector<int> minPartition(int N)
    {
        // code here
        vector<int> dp(N+1,N);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        
        vector<int> currency={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        vector<int> coins;
        
        while(N)
        {
            int index=lower_bound(currency.begin(), currency.end(), N+1)-currency.begin()-1;
            
            coins.push_back(currency[index]);
            N-=currency[index];
        }
        return coins;
    }
