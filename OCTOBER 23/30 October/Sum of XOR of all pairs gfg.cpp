class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	vector<int> count(32,0);
    	for(int i=0; i<n; i++)
    	{
    	    for(int j=0; j<31; j++)
    	        count[j] += ((arr[i]&(1<<j)) != 0);
    	}
    // 	for(int i=0; i<32; i++)
    	   // cout<<count[i]<<" ";
    // 	cout<<endl;
    	long long XORsum = 0;
    	for(int i=0; i<n; i++)
    	{
    	    for(int j=0; j<31; j++)
    	    {
    	        if(arr[i]&(1<<j))
    	            XORsum += ((1ll<<j)*(n-count[j]));
    	       // else
    	           // XORsum += ((1ll<<j)*(count[j]));
    	    }
    	   // cout<<i<<" "<<XORsum<<endl;
    	}
    	return XORsum;
    // 	0 1
    // 	1 0
    // 	0 1
    // 	1 0
    // 	0 1
    }
};
