class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        //  f(0) = 0
        //  f(1) = 1
        //  f(2) = 1
        //  f(3) = 2
        //  f(4) = 3
        //  f(5) = 5
        if(n<=2)
            return 1;
        long long f_n = 1, f_n_1=1, f_n_2=1;
        long long mod = 1e9+7;
        
        for(int i=3; i<=n; i++)
        {
            f_n = (f_n + f_n_1)%mod;
            f_n_1 = (f_n - f_n_1+mod)%mod;
        }
        return f_n;
    }
};
