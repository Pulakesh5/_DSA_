class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0], arr[1]);
        
        for(int i=1; i<(n-1); i++)
        {
            if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
                return i;
        }
        
        
        if(arr[0]>=arr[1])
            return 0;
        if(arr[n-2]<=arr[n-1])
            return n-1;
    }
};
