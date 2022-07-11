vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    sort(a,a+n);
    long long sum=0;
    int j=0;
    vector<int> ans(n);
    for(int i=n-1;i>=(n/2);i--)
    {
        sum+=a[i];
        ans[j]=a[i];
        j+=2;
    }
    j=1;
    for(int i=0;i<(n/2);i++)
    {
        sum-=a[i];
        ans[j]=a[i];
        j+=2;
    }
    
    if(sum<=0) return {-1};
    return ans;
}
