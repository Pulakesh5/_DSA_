    long long mod=1e9+7;
    long long _pow(int n)
    {
        if(n==0) return 1;
        long long res=_pow(n/2);
        if(n&1)
        {
            return (((res*res)%mod)*2)%mod;
        }
        else
            return ((res*res)%mod);
    }
    long long numberOfSubsequences(int N, long long A[]){
        // code here 
        int count=0;
        for(int i=0;i<N;i++)
        {
            if(!(A[i]&(A[i]-1))) count++;
        }
        return (_pow(count)-1);
    }
