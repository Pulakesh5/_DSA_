class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int zero = 0;
	    int z=n;
	   // while(z<n && arr[z]!=0)
	       // z++;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i]!=0)
	        {
	            if(z>i)
	                continue;
	            else
	            {
	                swap(arr[i], arr[z]);
	                while(z<n && arr[z]!=0)
	                    z++;
	            }
	        }
	        else
	            z = min(z,i);
	    }
	    
	}
};
