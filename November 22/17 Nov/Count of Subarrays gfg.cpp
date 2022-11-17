class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	   // stack<int> stk;
	   // stk.push(-1);
	   long long pos=-1,t,NonSub=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<=k) continue;
	        t=(i-pos-1);
	        pos=i;
	        NonSub+=((t*(t+1))/2);
	    }
	    t=(n-pos-1);
	    NonSub+=((t*(t+1))/2);
	    
	    return (1ll*n*(n+1)/2)-NonSub;
	}
};
