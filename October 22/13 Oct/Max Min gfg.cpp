class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	//code here.
    	int mn=INT_MAX,mx=INT_MIN;
    	for(int i=0;i<N;i++)
    	{
    	    mn=min(mn,A[i]);
    	    mx=max(mx,A[i]);
    	}
    	return mx+mn;
    }

};
