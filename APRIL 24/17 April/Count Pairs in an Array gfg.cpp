class Solution{
    private:
    int pairCount = 0 ;
    void merge(int *arr, int s, int e)
    {
        int mid = (s+e)/2;
        int i=s; 
        int j=mid+1;
        
        vector<int> tmp;
        
        while(i<=mid && j<=e)
        {
            if(arr[i]>arr[j])
            {
                tmp.push_back(arr[i]);
                pairCount += (e-j+1);
                i++;
            }
            else
            {
                tmp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
            tmp.push_back(arr[i]);
            i++;
        }
        
        while(j<=mid)
        {
            tmp.push_back(arr[j]);
            j++;
        }
        
        i = s;
        for(auto it:tmp)
        {
            arr[i] = it;
            i++;
        }
    }
    void mergeSort(int *arr, int s, int e)
    {
        if(s>=e)
            return;
        int mid = (s+e)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, e);
    }
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        for(int i=0; i<n; i++)
            arr[i] = arr[i]*i;
        mergeSort(arr, 0, n-1);
        return pairCount;
    }
};
