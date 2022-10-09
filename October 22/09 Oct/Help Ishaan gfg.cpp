	    bool isPrime(int N)
	    {
	        bool isPrime=true;
	        if(N==1) return false;
	        for(int i=2;i<=sqrt(N) && isPrime;i++)
		    {
		        if((N%i)==0)
		            isPrime=false;
		    }
		    return isPrime;
	    }
		int NthTerm(int N){
		    // Code here
		    bool flag=isPrime(N);
		    
		    if(flag) return 0;
		    
		    int l=N-1,r=N+1;
		    bool l_flag,r_flag;
		    while(l>1)
		    {
		        l_flag=isPrime(l);
		        if(l_flag) return (N-l);
		        r_flag=isPrime(r);
		        if(r_flag) return (r-N);
		        l--;
		        r++;
		    }
		    
		    while(1)
		    {
		        r_flag=isPrime(r);
		        if(r_flag) return (r-N);
		        r++;
		    }
		    return 0;
		}
