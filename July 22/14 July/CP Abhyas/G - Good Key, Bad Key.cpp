bool solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    input(a,n);
    
    int ans=INT_MIN,t=0,sum=0;
    for(int i=0;i<n;i++){
        t=0;
        for(int j=i;j<min(n,i+32);j++){
            t+=(a[j]>>(j-i+1));
        }
        ans=max(ans,sum+t);
        sum+=(a[i]-k);
    }
    
    cout<<max(ans,sum);
    
    return 0;
    
}
