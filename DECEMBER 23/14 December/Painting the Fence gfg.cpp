class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        // 0 1 2
        
        // 00 01 02 10 11 12 20 21 22 (3, 6)
        
        // 001 002, 010 011 012, 020 021 022, 100 101 102
        // 110 112, 120 121 122, 200 201 202, 210 211 212
        // 220 221 (6, (6+3)*3-3)
        if(n==1)
            return k;
        
        if(k==1)
        {
            if(n<=2)
                return 1;
            else
                return 0;
        }
        
        long long MOD=1e9+7;
        long long same=k, not_same=1ll*k*k-k, t;
        for(int i=3; i<=n; i++)
        {
            t = ((same+not_same)*k-same+MOD)%MOD;
            same = not_same;
            not_same = (t-not_same+MOD)%MOD;
        }
        return (same+not_same)%MOD;
    }
};
