    long long mod=1e9+7;
    long long modMul(long long a, long long b, long long mod)
    {
        long long res = 0; 
        a %= mod;
        while (b) {
            if (b & 1)
                res = (res + a) % mod;
            a = (2 * a) % mod;
            b >>= 1; 
        }
        return res;
    }
    long long int gcdExtended(long long int a, long long int b, long long int* x, long long int* y)
    {
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }
        long long int x1, y1; 
      
        long long int gcd = gcdExtended(b % a, a, &x1, &y1);
      
        *x = y1 - (b / a) * x1;
        *y = x1;
        return gcd;
    }
    long long int modInverse(long long int b, long long int m)
    {
        long long int x, y; // used in extended GCD algorithm
        long long int g = gcdExtended(b, m, &x, &y);
      
        // Return -1 if b and m are not co-prime
        if (g != 1)
            return -1;
        // m is added to handle negative x
        return (x % m + m) % m;
    }
    long long int modDivide(long long int a, long long int b, long long int m)
    {
        a = a % m;
        long long int inv = modInverse(b, m);
        if (inv == -1)
            return 0;
        else
            return (inv * a) % m;
    }
    bool check(long long number, long long C, long long D)
    {
        int digit;
        while(number)
        {
            digit=number%10;
            if(digit==C || digit==D)
                return true;
            number/=10;
        }
        return false;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        long long x=1;
        vector<long long> nCr(N+1);
        nCr[0]=1;
        for(int i=1;i<=N;i++)
        {
            x = modMul(x, (N + 1 - i), mod);
            x = modDivide(x, i, mod);
            nCr[i]=x;
        }
        // for(int i=0;i<=N;i++)   cout<<nCr[i]<<" ";
        // cout<<endl;
        if(A==B)
            return check(N*A,C,D);
        else if(A>B)
            swap(A,B);
        long long SumofDigitMin=N*A, SumofDigitMax=N*B; 
        long long r=0;
        long long bestInteger=0;
        while(SumofDigitMin<=SumofDigitMax)
        {
            if(check(SumofDigitMin, C, D))
                bestInteger=(bestInteger+nCr[r])%mod;
            //cout<<"{ "<<r<<" "<<SumofDigitMin<<"} ";
            r++;
            SumofDigitMin-=A;
            SumofDigitMin+=B;
        }
        //cout<<endl;
        return bestInteger;
        
    }
