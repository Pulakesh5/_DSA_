int gcd(int a,int b){
    if(b==0) return a;
    if(a==0) return b;
    if(a==b) return a;
    if(a>b) return gcd(b,a%b);
    return gcd(b%a,a); 
}
bool solve(){
    int n,x;
    cin>>n;
    
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool flag=true;
    
    for(int i=1;i<n && flag;i++)
    {
        if(a[i]!=a[0])
            flag=false;
    }    
    if(flag)
    {
        cout<<-1;
        return 0;
    }
    sort(all(a));
    // for(auto it:a)
    //     cerr<<it<<" ";
    // cerr<<'\n';
    int ans=0;
    int mn = a[0];
    for(int i=0;i<n;i++){
        //cerr<<i<<" "<<ans<<" "<<(a[i]-mn)<<'\n';
        ans = gcd(ans,a[i]-mn);
        //cerr<<i<<" "<<ans<<" "<<(a[i]-mn)<<'\n';
    }
    cout<<ans;
    return 0;
}
