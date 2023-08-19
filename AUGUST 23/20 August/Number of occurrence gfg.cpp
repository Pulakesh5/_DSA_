class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int lower_bound(int arr[], int n, int x)
	{
	    int l = 0, r= n-1, mid, index=-1;
	    while(l<=r)
	    {
	        mid = (l+r)/2;
	       // cout<<mid<<" "<<l<<" "<<r<<endl;
	        if(arr[mid]==x)
	        {
	            index=mid;
	            r=mid-1;
	        }
	        else if(arr[mid]<x)
	            l = mid+1;
	        else
	            r = mid-1;
	    }
	    return index;
	}
	int upper_bound(int arr[], int n, int x)
	{
	    int l = 0, r= n-1, mid, index=-1;
	    while(l<=r)
	    {
	        mid = (l+r)/2;
	       // cout<<mid<<" "<<l<<" "<<r<<endl;
	        if(arr[mid]==x)
	        {
	            index=mid;
	            l=mid+1;
	        }
	        else if(arr[mid]<x)
	            l = mid+1;
	        else
	            r = mid-1;
	    }
	    return index;
	}
	int count(int arr[], int n, int x) {
	    // code here
	   // cout<<"called lb\n";
	    int lb = lower_bound(arr, n, x);
	   // cout<<"called ub\n";
	    int ub = upper_bound(arr, n, x);
	   // cout<<lb<<" "<<ub<<endl;
	    if(lb==-1 || ub==-1)
	        return 0;
	    return (ub-lb+1);
	}
};
