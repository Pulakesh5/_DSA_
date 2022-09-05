    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> vp(n);
    	for(int i=0;i<n;i++)
    	    vp[i]={arr[i],dep[i]};
    	sort(vp.begin(),vp.end());
    	
    	priority_queue<int,vector<int>,greater<int>> dep_time;
    	//dep_time.push(vp[0].second);
    	
    	int arr_time, platforms=0;
    	
    	for(int i=0;i<n;i++)
    	{
    	    arr_time=vp[i].first;
    	    
    	    while(!dep_time.empty() && arr_time > dep_time.top())
    	        dep_time.pop();
    	        
    	    dep_time.push(vp[i].second);
    	    platforms=max(platforms,(int)dep_time.size());
    	}
    	return platforms;
    }
