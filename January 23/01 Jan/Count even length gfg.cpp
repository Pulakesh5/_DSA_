#define ll long long
    
    ll mod=1e9+7;
    
    ll binpow(ll a,ll b){
        
        ll res=1;
        a%=mod;
        while(b){
            
            if(b&1){
                res=((res%mod)*(a%mod))%mod;
            }
            a=((a%mod)*(a%mod))%mod;
            b>>=1;
        }
        return res;
    }
    
    ll fact[100005];
    ll finv[100005];
    
    ll fermat_inv(ll a){
        
        return binpow(a,mod-2)%mod;
    }
    
    void factorial(int n){
     
        fact[0]=1;
        finv[0]=1;
        for(int i=1;i<n;i++){
            fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
            finv[i]=fermat_inv(fact[i]);
        }
        
    }
    
    ll ncr(ll n,ll r){
        
        if(r>n)
           return 0;
        
        if(n==0 || r==0 || n==r){
            return 1;
        }
        
        ll ans=((fact[n]%mod)*(finv[n-r]%mod))%mod;
        ans=((ans%mod)*(finv[r]%mod))%mod;
        return ans;
    }

    public:
        int compute_value(int n)
    	{
    	    // Code here
    	    factorial(n+1);
    	    ll ans=2;
    	    for(int i=1;i<n;i++){
    	        
    	      ll p=ncr(n,i)%mod;
    	      ans=(ans%mod+(p*p)%mod)%mod;
    	        
    	    }
    	    return ans;
    	   
    	    
    	}
