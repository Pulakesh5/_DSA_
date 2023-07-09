class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int mx = 0, index;
        for(int i=0; i<n; i++)
        {
            if(arr[i]<=0)
                arr[i] = 0;
            if(arr[i]>mx)
                mx = arr[i];
        }
        mx++;
        for(int i=0; i<n; i++)
        {
            if(arr[i]>0)
            {
                index = (arr[i]%mx) - 1;
                if(index<n && index>=0)
                    arr[index]+=mx;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]<mx)
                return i+1;
        }
        return n+1;
    } 
};
