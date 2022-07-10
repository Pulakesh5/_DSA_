bool solve(){
    int n,q;
    cin>>n>>q;
    int station;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        cin>>station;
        mp[station].push_back(i+1);
    }
    
    for(auto &pr:mp){
        sort(all(pr.second));
    }
    
    int a,b;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(mp.find(a)==mp.end() || mp.find(b)==mp.end())
            cout<<"NO";
        else if(a==b)
            cout<<"YES";
        else{
            if(upper_bound(all(mp[b]),mp[a][0])!=mp[b].end())
                cout<<"YES";
            else
                cout<<"NO";
        }
        cout<<endl;
    }

    return 0;
    
}
