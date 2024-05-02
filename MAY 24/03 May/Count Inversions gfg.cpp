class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return _mergeSort(arr, temp, 0, N-1);
    }
    
    private:
        
    long long _mergeSort(long long arr[], long long temp[], int l, int r)
    {
        long long mid, inversion_count = 0;
        if(r>l)
        {
            mid = (l+r)/2;
            inversion_count += _mergeSort(arr, temp, l, mid);
            inversion_count += _mergeSort(arr, temp, mid+1, r);
            
            inversion_count += _merge(arr, temp, l, mid+1, r);
        }
        return inversion_count;
    }
    
    
    long long _merge(long long arr[], long long temp[], int l, int mid, int r)
    {
        int p1=l, p2=mid;
        int k = l;
        long long inv_count = 0;
        while((p1<=mid-1) && (p2<=r))
        {
            if(arr[p1]<=arr[p2])
                temp[k++] = arr[p1++];
            else
            {
                temp[k++] = arr[p2++];
                inv_count += (mid-p1);
            }
        }
        
        while(p1<=mid-1)
            temp[k++] = arr[p1++];
        
        while(p2<=r)
            temp[k++] = arr[p2++];
        
        for(int i=l; i<=r; i++)
            arr[i] = temp[i];
        
        return inv_count;
    }
    
    
};
