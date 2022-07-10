bool solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    
    input(a,n);
    sort(all(a));
    
    int ans=n;
    for(int i=1;i<n;i++)
        ans+=a[i];
    ans+=a[n-1];
    if(ans>m) cout<<"NO";
    else cout<<"YES";
    return 0;
    
}
