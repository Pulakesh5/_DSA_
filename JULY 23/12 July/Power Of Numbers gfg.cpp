class Solution{
    public:
    //You need to complete this fucntion
    long long mod = 1e9+7;
    long long binaryExpo(long long N, long long p)
    {
        if(p==1)
            return N;
        long long mul = binaryExpo(N,p/2), ans;
        ans = (mul * mul)%mod;
        if(p&1)
            ans = (ans*N)%mod;
        return ans;
    }
    long long power(int N,int R)
    {
       //Your code here
       return binaryExpo(N,R);
    }

};
