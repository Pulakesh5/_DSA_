class Solution{
    private:
    long long calculateCost(int n, int height, int cost[], int h[])
    {
        long long totalCost = 0ll;
        for(int i=0; i<n; i++)
            totalCost += 1ll*(abs(h[i]-height)*cost[i]);
        return totalCost;
    }

	public:
	long long int Bsearch(int n, int h[], int cost[]) 
	{ 
		// Your code goes here
		int low = *min_element(h, h+n), high=*max_element(h, h+n);
		for(int i=0; i<n; i++)
            high = max(high, h[i]);
		long long minCost = (1ll<<62), ans, eqHeight;
		long long lowCost, upCost;
		
		while(low<=high)
		{
	        eqHeight = (low+high)/2;
		    
		    minCost = calculateCost(n, eqHeight, cost, h);
		    upCost = calculateCost(n, eqHeight+1, cost, h);
		    lowCost = calculateCost(n, eqHeight-1, cost, h);
		  //  cout<<eqHeight<<" : "<<minCost<<", "<<lowCost<<", "<<upCost<<endl;
		    if(minCost<upCost && minCost<lowCost)
		    {
		        return minCost;
		    }
		    else if(lowCost<minCost)
		        high = eqHeight-1;
		    else
		        low = eqHeight+1;
		    ans = min(minCost, ans);
		}
		return ans;
		
	}
		 

};
