	void convert(int arr[], int n) {
	    // code here
	    vector<pair<int,int>> vp;
	    for(int i=0;i<n;i++)
	        vp.push_back(make_pair(arr[i],i));
	   sort(vp.begin(),vp.end());
	   
	   for(int i=0;i<n;i++)
	    arr[vp[i].second]=i;
	    
	}
