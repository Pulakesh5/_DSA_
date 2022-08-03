bool solve(){
    int n,x;
    cin>>n>>x;
    if(x<n)
        cout<<-1;
    else if(x==n){
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
    }
    else{
        cout<<x-(n-1)<<" ";
        for(int i=1;i<=n;i++)
        {
            if(i==(x-n+1)) continue;
            cout<<i<<" ";
        }
    }
    
    return 0;
}
