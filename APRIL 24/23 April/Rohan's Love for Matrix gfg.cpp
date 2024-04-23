class Solution {
  public:
    int firstElement(int n) {
        // code here
        if(n<=2)
            return 1;
        // this is actually fibonacci sequence problem
        const long long MOD = 1e9+7;
        long long a = 1, b=1;
        for(int i=3; i<=n; i++)
        {
            a = (a+b)%MOD;
            b = (a-b+MOD)%MOD;
        }
        return a;
        
    }
    // f(n) = a00*f(n-1) + a01*f(n-2)
    // f(n-1) = a10*f(n-1) + a11*f(n-2)
};
