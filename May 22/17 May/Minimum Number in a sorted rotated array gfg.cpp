class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        int last=arr[high];
        while(low<high){
            int mid= (high+low)>>1;
            if(arr[mid]>last) low=mid+1;
            else high=mid;
        }
        return arr[low];
    }
};
