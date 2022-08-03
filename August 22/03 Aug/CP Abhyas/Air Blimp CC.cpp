bool solve(){
    int n=0,x=0,y=0;
    cin>>n>>x>>y;
    vector<int> a(n),dp(n+1,0);
    
    for(int i=0;i<n;i++) cin>>a[i];
    //cerr<<n<<" "<<x<<" "<<y<<endl;
    int sadness=0;
    for(int i=n-1;i>=0;i--){
        sadness=(a[i]-dp[i+1]*y);
        ////cerr<<sadness<<"\n";
        dp[i]=dp[i+1];
        dp[i]+=max(0ll,min((sadness+y-1)/y,(sadness+x-1)/x));
    }    
    cout<<dp[0];
    return 0;
}
