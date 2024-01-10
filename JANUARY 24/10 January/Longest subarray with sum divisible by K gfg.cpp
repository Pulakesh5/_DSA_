class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    map<int, int> lastPos;
	    lastPos[0]=-1;
	    int contSum=0, maxLength=0, rem;
	    for(int i=0; i<n; i++)
	    {
	        contSum+=arr[i];
	        rem = (contSum%k+k)%k;
	        if(lastPos.find(rem)==lastPos.end())
	            lastPos[rem]=i;
	        else
	            maxLength=max(maxLength, i-lastPos[rem]);
	       // cout<<rem<<" "<<lastPos[rem]<<endl;
	    }
	    return maxLength;
	}
};
