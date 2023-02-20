int countPaths(int N){
        // code here 
        if(N<=1) return 0;
        long long ans=0, mod=1e9+7;
        for(int i=2;i<=N;i++)
        {
            if(i%2)
                ans = (3ll*(ans-1))%mod;
            else
                ans = (3ll*(ans+1))%mod;
            ans = ans%mod;
        }
        return ans;
    }
