class Solution {
    private static final int MOD = 1000000007;
    
    private static final int MAXN = 100000;
    
    private static long[] fact = new long[MAXN + 1];
    private static long[] invFact = new long[MAXN + 1];
    
    static {
        fact[0] = 1L;
        for (int i = 1; i <= MAXN; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[MAXN] = modExp(fact[MAXN], MOD - 2, MOD); 
        for (int i = MAXN - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }
    
    private static long modExp(long base, int exp, int mod) {
        long result = 1L;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    private static long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
    
    public int countGoodArrays(int n, int m, int k) {
        if (n == 1) {
            return (k == 0) ? m : 0;
        }
        
        long choose = nCr(n - 1, k);
        long ways = choose % MOD;
        
        ways = (ways * m) % MOD;
        ways = (ways * modExp(m - 1, n - k - 1, MOD)) % MOD;
        
        return (int) ways;
    }
}
