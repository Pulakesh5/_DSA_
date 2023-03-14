        int maxEarn(vector<int> &a, vector<vector<int>> &dp, int l, int r)
        {
            if(l>r) return 0;
            
            if(dp[l][r]!=-1) return dp[l][r];
            
            int ans = INT_MIN, earn=1;
            int n = a.size();
            
            for(int i=l;i<=r;i++)
            {
                earn = a[i];
                if((l-1)>=0)
                    earn*=a[l-1];
                if((r+1)<n)
                    earn*=a[r+1];
                earn +=( maxEarn(a, dp, l, i-1) + maxEarn(a, dp, i+1, r));
                ans = max(ans,earn);
            }
            
            return dp[l][r] = ans;
            
        }
        mid = l+(r-l)/2;
        
        int maxCoins(int N, vector <int> &a)
        {
                vector<vector<int>> dp(N,vector<int>(N,-1));
                int l=0, r= a.size() - 1;
                return maxEarn(a, dp, l, r);
        }
