    int sumOfNaturals(int n) {
        // code here 
        long long N = n;
        long long mod = 1e9+7;
        return ((N*(N+1))/2)%mod;
    }
