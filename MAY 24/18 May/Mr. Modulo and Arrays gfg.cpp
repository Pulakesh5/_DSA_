int findIndex(int arr[], int n, int i)
{
    int s=0, e=n-1, mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]>=i)
            e = mid-1;
        else if(arr[mid]<i)
            s = mid+1;
    }
    return s;
}

int maxModValue(int arr[], int n)
{
    sort(arr, arr+n);
    
    int ans = 0, MAX = arr[n-1], ind;
    for(int j=n-2; j>=0; j--)
    {
        if(ans>=arr[j])
            break;
        if(arr[j]==arr[j+1])
            continue;
        for(int i=2*arr[j]; i<=arr[n-1]+arr[j]; i+=arr[j])
        {
            ind = findIndex(arr, n, i);
            ans = max(ans, arr[ind-1]%arr[j]);
        }
    }
    return ans;
}
