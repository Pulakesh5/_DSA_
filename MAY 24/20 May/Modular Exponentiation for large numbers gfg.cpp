class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n==0)
		        return 1ll;
            if(n==1)
                return x;
            long long halfPow = PowMod(x, n/2, M);
            halfPow = (halfPow%M) *(halfPow%M);
            halfPow = halfPow%M;
            if(n&1)
                halfPow = (halfPow*x)%M;
            return halfPow;
		}
};
