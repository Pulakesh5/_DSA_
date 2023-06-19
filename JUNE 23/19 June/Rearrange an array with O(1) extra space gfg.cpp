class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        // Your code here
        long long N = n;
        // arr[i]%N = original arr[i]
        // arr[i]/N = arr[arr[i]]
        
        for(int i=0; i<n; i++)
        {
            arr[i] = arr[i] + (arr[arr[i]]%N)*N;
            
        }
        for(int i=0; i<n; i++)
            arr[i] = arr[i]/N;
    }
};
