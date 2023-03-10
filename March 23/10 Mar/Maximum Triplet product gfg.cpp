    long long maxTripletProduct(long long arr[], int n)
    {
    	sort(arr,arr+n);
    	
    	long long mn1 = arr[0];
    	long long mn2 = arr[1];
    	
    	long long mx1 = arr[n-1];
    	long long mx2 = arr[n-2];
    	long long mx3 = arr[n-3];
    	
    	return max((mn1*mn2*mx1),(mx3*mx2*mx1));
    }
