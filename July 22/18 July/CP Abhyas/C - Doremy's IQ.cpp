bool solve(){
    int n,iq;
    cin>>n>>iq;
    vector<int> a(n);
    input(a,n);
    
    vector<int> ans(n,0),need(n,0);
    need[n-1]=1;
    for(int i=n-2;i>=0;i--){
        need[i] = need[i+1] + (a[i]>need[i+1]);
    }
    
    for(int i=0;i<n && iq>0;i++){
        if(a[i]<=iq || iq>=need[i]){
            ans[i]=1;
            iq-=(a[i]>iq);
        }
        else ans[i]=0;
        //cerr<<i<<" "<<iq<<endl;
    }
    for(int i=0;i<n;i++)
    cout<<ans[i];
    return 0;
    
}
