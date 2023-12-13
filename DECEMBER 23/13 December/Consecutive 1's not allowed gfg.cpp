class Solution{
public:
	#define ll long long
	ll countStrings(int n) {
	    // code here
	    //N=1 0 1
	    //N=2 00 01 10
	    //N=3 000 001 010 100 101
	   
	    ll MOD = 1e9+7;
	    ll a=1, b=1, t1;
	    for(int i=2; i<=n; i++)
	    {
	        t1 = (a+b)%MOD;
	        b = a;
	        a = t1;
	    }
	    return (a+b)%MOD;

	}
};
