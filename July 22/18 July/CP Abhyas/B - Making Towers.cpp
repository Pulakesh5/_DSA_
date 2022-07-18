bool solve(){
    int n,m;
    cin>>n;
    vector<int> a(n);
    input(a,n);
    
    map<int,vector<int>> mp;
    vector<int> ans(n+1,0);
    for(int i=0;i<n;i++){
        
        mp[a[i]].push_back(i);
    }
    for(auto &pr:mp){
        int n=pr.second.size(),odd=0,even=0;
        //cerr<<"here\n";
        vector<int> v=pr.second;
        for(int i=1;i<n;i++){
            if((v[i]-v[i-1])%2==1) odd++;
        }
        ans[pr.first]=odd+1;
    }
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
    
}
