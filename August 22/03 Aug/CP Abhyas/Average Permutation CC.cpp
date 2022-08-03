bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int num=n;
    for(int i=0;i<(n/2);i++)
    {
        a[i]=num--;
        a[n-1-i]=num--;
    }
    if(n&1) a[n/2]=1;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        return 0;
}
