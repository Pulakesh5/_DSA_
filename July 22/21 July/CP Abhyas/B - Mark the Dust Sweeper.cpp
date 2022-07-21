bool solve(){
    int n,x;
    cin>>n;
    vector<int> a(n);
    input(a,n);
    int ans=0;
    int i=0;
    while(i<n && a[i]==0) i++;
    for(int j=i;j<(n-1);j++){
        ans+=max(1ll,a[j]);
    }
    cout<<ans;
    return 0;
}
