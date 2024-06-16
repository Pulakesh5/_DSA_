class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<bool> primes(n+5, true);
        primes[0] = false;
        primes[1] = false;
        for(int i=2; i<=n; i++)
        {
            if(primes[i])
            {
                for(long long j=1ll*i*i; j<=n; j+=i)
                    primes[j] = false;
            }
        }
        for(int j=2; j<=(n/2); j++)
        {
            // cout<<j<<", "<<(n-j)<<" : "<<primes[j]<<" "<<primes[n-j]<<endl;
            if(primes[j] && primes[n-j])
            {
                return {j, n-j};
            }
        }
        return {-1,-1};
    }
};
