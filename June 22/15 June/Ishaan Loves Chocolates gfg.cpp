int chocolates(int arr[], int n)
{
    // Complete the function
    int last=INT_MAX;
    
    for(int i=0;i<n;i++)
        if(arr[i]<last)
            last=arr[i];
    
    return  last;
    
}
