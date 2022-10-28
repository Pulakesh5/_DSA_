		int NthTerm(int n){
		    // Code  here
		    long long a=2;
		    for(int i=2;i<=n;i++)
		        a=((i*a)%mod+1)%mod;
		    return a;
		}
