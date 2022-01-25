ll fl(ll a, ll b){
    ll temp=a/b;
    while(temp*b > a)
        temp--;
    return temp;
}
bool solve(){
    int n;
    ll k;
    cin>>n>>k;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(all(arr));
    
    vector<ll> sum(n+1,0);
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i]+arr[i];
    }
    ll ans=1e18;
    for(int i=0;i<n;i++){
        ll t= arr[0] - fl(k-sum[n-i]+arr[0], i+1);;
        ans = min(i + max(t,0LL), ans);
    }
    cout<<ans;
    
    return 0;
}
