bool solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    input(a,n);
    vector<int> fr(n+2,0),rev(n+2,0);
    for(int i=1;i<n;i++)
        fr[i]=max(0ll,a[i-1]-a[i])+fr[i-1];
    for(int i=n-1;i>0;i--)
        rev[i]=rev[i+1]+max(0ll,a[i]-a[i-1]);
    
    int start,end;
    while(m--){
        cin>>start>>end;
        if(start<=end){
            cout<<fr[end-1]-fr[start-1]<<'\n';
        }
        else{
            cout<<rev[end]-rev[start]<<'\n';
        }
    }
    
    return 0;
}
