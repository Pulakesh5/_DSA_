class Solution {
  public:
    // Function to count inversions in the array.
    
    int merge(vector<int> &arr, int l, int mid, int r) {
        int count = 0;
        int i=l, j=mid+1, k=0;
        vector<int> temp(r-l+1);
        
        while(i<=mid && j<=r) {
            if(arr[i]<=arr[j])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                count += (mid-i+1);
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid)
            temp[k++] = arr[i++];
        while(j<=r)
            temp[k++] = arr[j++];
        for(int i=l; i<=r; i++)
            arr[i] = temp[i-l];
        return count;
    }
    
    
    int mergeSort(vector<int> &arr, int l, int r) {
        if(l>=r)
            return 0;
        int midPoint = (l+r)/2;
        int count = 0;
        
        count += mergeSort(arr, l, midPoint);
        
        count += mergeSort(arr, midPoint+1, r);
        
        count += merge(arr, l, midPoint, r);
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int N = arr.size();
        int countOfInversion = mergeSort(arr, 0, N-1);
        return countOfInversion;
    }
};
