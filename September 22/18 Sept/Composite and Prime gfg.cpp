		int Count(int L, int R){
		    // Code here
		    int j;
		    set<int> Nonprimes;
		    for(int i=2;(i*i)<=R;i++)
		    {
		        j=2;
		        while(i*j<=R)
		        {
		            if(i*j>=L) Nonprimes.insert(i*j);
		            j++;
		        }
		    }
		    int nonPrimeCount=Nonprimes.size();
		    int ans=nonPrimeCount-(R-L-nonPrimeCount);
		    if(L<=1) return ans;
		    return ans-1;
		}
