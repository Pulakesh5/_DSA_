int* greaterElement(int arr[], int n)
{
    vector<int> v(arr,arr+n);
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<n;i++){
        int ind = upper_bound(v.begin(), v.end(),arr[i]) - v.begin();
        if(ind == n) arr[i]=-10000000;
        else arr[i]=v[ind];
    }
    return arr;
}
