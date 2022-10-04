    long long mod=1e9+7; 
    
    long long modInv(long long n)
    {
        n%=mod;
        
        long long p=mod-2;
        unsigned long long res=1;
        //cout<<n<<" "<<p<<endl;
        while(p)
        {
            if(p&1)
                res=(res*n)%mod;
            n=(n*n)%mod;
            p=p>>1;
        }
        //cout<<res<<endl;
        return res;
    }
    unsigned long long nCr(int n, int r)
    {
        vector<unsigned long long> fac(n+1,1ll);
        for(int i=2;i<=n;i++)
            fac[i]=(1ll*fac[i-1]*i)%mod;
        //for(int i=0;i<=10;i++) cout<<i<<": "<<fac[i]<<endl;
        
        return ((fac[n]*modInv(fac[r])%mod)%mod*modInv(fac[n-r])%mod)%mod;
    }
    long long int numberOfPaths(int m, int n){
        // code here
        return nCr(m+n-2,m-1);
    }
