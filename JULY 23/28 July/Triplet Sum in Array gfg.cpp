class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long mul=1ll, maxProductSubarray = arr[0];
	    long long prefMul = 1ll, sufMul = 1ll;
	    for(int i=0; i<n; i++)
	    {
	        if(prefMul==0)
	            prefMul = arr[i];
	        else
	            prefMul = prefMul*arr[i];
	        
	        if(sufMul==0)
	            sufMul = arr[n-1-i];
	        else
	            sufMul = arr[n-1-i]*sufMul;
	        maxProductSubarray = max({maxProductSubarray, prefMul, sufMul});
	    }
	    return maxProductSubarray;
	}
};
