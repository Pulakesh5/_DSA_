class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    if(n<=2)
		        return n;
		    long long MOD=1e9+7;
		    long long a=1,b=2,t;
		    for(int i=3; i<=(n+1); i++)
		    {
		        t=(a+b)%MOD;
		        a=b;
		        b=t;
		    }
		    return a; 
		}
};
