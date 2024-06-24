class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q<=1 || q>2*n)
            return 0;
        if(q<=n+1)
            return q-1;
        return (2*n-q+1);
    }
};
