class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int lb = lower_bound(arr, arr+n, k) - arr;
        if(lb==n)
            return arr[n-1];
        
        int diff1 = (lb-1)>=0 ? (k-arr[lb-1]) : INT_MAX;
        int diff2 = (arr[lb]-k);
        
        if(diff1<diff2)
            return arr[lb-1];
        else
            return arr[lb];
    } 
};
