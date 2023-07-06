class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high){
            int pivot = partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot=arr[high];
       int pivotPoint=low-1;
       
       for(int i=low;i<high;i++)
       {
           if(arr[i]<pivot)
           {
                pivotPoint++;
                swap(arr[i],arr[pivotPoint]);
           }
       }
       pivotPoint++;
       swap(arr[pivotPoint],arr[high]);
       
       return pivotPoint;
    }
};
