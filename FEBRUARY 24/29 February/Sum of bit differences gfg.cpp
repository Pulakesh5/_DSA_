class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long long count=0;
	    for(int i=31; i>=0; i--)
	    {
	        long long a=0;
	        for(int j=0; j<n; j++)
	        {
	            a+=((arr[j]>>i)&1);
	        }
	        count += 2ll*(a)*(n-a);
	    }
	    return count;
	}
};
