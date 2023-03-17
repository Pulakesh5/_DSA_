long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long subarray=0;
    int zeroes = 0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            subarray+=((zeroes*(zeroes+1))/2);
            zeroes=0;
        }
        else
            zeroes++;
    }
    
    subarray+=((1ll*zeroes*(zeroes+1))/2);
    
    return subarray;
}
