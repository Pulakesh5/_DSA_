bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    set<int> st;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int single=0,couple=0;
    for(auto it:mp){
        if(it.second>1)
            couple++;
        else
            single++;
    }
    cout<<couple+(single+1)/2;
 
    return 0;
}
