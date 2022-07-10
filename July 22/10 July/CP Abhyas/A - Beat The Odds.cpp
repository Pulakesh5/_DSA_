bool solve(){
    int n;
    cin>>n;
    int x,odd=0,even=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x&1) odd++;
        else even++;
    }
    cout<<min(n-even,n-odd);
    return 0;
    
}
