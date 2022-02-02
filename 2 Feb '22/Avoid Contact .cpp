bool solve(){
    
    int x,y;
    cin>>x>>y;
    
        int ans=0;
    if((x-y)>0)
        ans+=2*y;
    else
        ans+=(2*y-1);
    ans+=(x-y);
    cout<<ans;
    
    
    
    return 0;
}
