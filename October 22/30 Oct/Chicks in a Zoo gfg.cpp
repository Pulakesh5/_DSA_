	long long int NoOfChicks(int n){
	    // Code here
	    //for(int i=1;i<=)
	    vector<long long> chicks(40,0);
	    chicks[1]=1;
	    long long deads=0;
	    for(int i=2;i<=n;i++)
	    {
	        if(i<7){
	            chicks[i]=chicks[i-1]*3;
	            continue;
	        }
	        //
	        if(i==7)
	        chicks[i]=3*(chicks[i-1]-chicks[i-6]);
	        else
	        chicks[i]=(3*chicks[i-1]-2*chicks[i-6]);
	    }
	    
	    return chicks[n];
	}
