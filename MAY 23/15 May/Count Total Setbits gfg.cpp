    long long countBits(long long n) {
        if(n<3) return n;
        long long x = log2(n);
        return (pow(2,x-1)*(x)) + (n-pow(2,x)+1) + countBits(n-pow(2,x));
    }
