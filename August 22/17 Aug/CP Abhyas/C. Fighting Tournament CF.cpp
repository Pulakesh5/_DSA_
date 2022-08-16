bool solve(){
    
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    a[0]=-1;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    
    vector<int> match;//(n+1);
    set<int> winners;
    //map<int,int> countOfWins;
    
    int winner=1,winnerPos=0,mx=0;
    if(a[1]>a[2]) winners.insert(1);
    for(int i=2;i<=n;i++)
    {
        if(a[winner]<a[i])
        {
            winner=i;
            winners.insert(winner);
            //winnerPos=i;
        }
        match.push_back(winner);
        //countOfWins[a[i]]++;
    }
    
    // for(auto it:match) cerr<<it<<" ";
    // cerr<<endl;
    
    int ind,round;
    
    while(q--){
        cin>>ind>>round;
        //ind--;
        //round--;
        if(winners.find(ind)==winners.end())
            cout<<0<<'\n';
        else{
            int lpos = lower_bound(all(match),ind) - match.begin();
            int upos = upper_bound(all(match),ind) - match.begin()-1;
            
            
            // debug(ind);
            // debug(lpos);
            // debug(upos);
            // cerr<<endl;
            int ans = min(upos,round-1)-lpos+1;
            
            if(a[ind]<a[winner])
                cout<<max(ans,0ll)<<'\n';
            else{
                if(round<n)
                    cout<<max(ans,0ll)<<'\n';
                else{
                    round-=(n-1);
                    ans+=round;
                    cout<<ans<<'\n';
                }
            }
            
        }
    }
    
    return 0;
}
