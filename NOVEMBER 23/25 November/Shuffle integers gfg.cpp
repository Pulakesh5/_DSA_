class Solution{
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    int start=1, end=n/2;
	    const int mx = 1e4;
	    // 1 2 3 4 5 6
	    for(int i=1; i<n; i++)
	    {
	        if(i&1)//if odd index, then attach second half number
	            arr[i] = (arr[end++]%mx)*mx + arr[i]%mx;
	        else
	            arr[i] = (arr[start++]%mx)*mx + arr[i]%mx;
	    }
	    for(int i=1; i<n; i++)
	        arr[i] = arr[i]/mx;
	}
};
