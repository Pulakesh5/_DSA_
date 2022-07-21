bool solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(2*n);
    input(a,2*n);
    sort(all(a));
    
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i+n]<a[i]+x)
        {
            cout<<"NO";
            return 0;
        }
        
    }
    cout<<"YES";
    return 0;
}
