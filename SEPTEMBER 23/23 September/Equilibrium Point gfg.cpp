class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long sum = 0;
        for(int i=0; i<n; i++)  sum+=a[i];
        long long prefSum = 0;
        for(int i=0; i<n; i++)
        {
            if((sum-a[i])==2*prefSum)
                return i+1;
            prefSum+=a[i];
        }
        return -1;
    }

};
