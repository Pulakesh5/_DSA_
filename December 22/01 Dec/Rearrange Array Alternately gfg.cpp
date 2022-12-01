    void rearrange(long long *arr, int n) 
    { 
    	
    	int start = 0;
    	int end = n - 1;
    	vector<int>ans;
    	while(start < (n / 2) and end < n)
    	{
    	    ans.push_back(arr[end]);
    	    ans.push_back(arr[start]);
    	    start++;
    	    end--;
    	}
    	if(n % 2 == 1)
    	{
    	    int element = n / 2;
    	    ans.push_back(arr[element]);
    	}
        for(int i = 0; i < n; i++)
        {
            arr[i] = ans[i];
        }
    	 
    }
