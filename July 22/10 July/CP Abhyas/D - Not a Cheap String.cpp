bool solve(){
    string s;
    cin>>s;
    int p,n=s.length();
    cin>>p;
    vector<int> mp[26];
    
    for(int i=0;i<n;i++){
        mp[s[i]-'a'].push_back(i);
    }
    int sum=0,sz;
    vector<int> a;
    for(int i=0;i<26 && sum<p;i++){
        
        if(mp[i].size()>0){
            sz=mp[i].size();
            if(sz>((p-sum)/(i+1)))
                sz=((p-sum)/(i+1));
            for(int j=0;j<sz;j++)
                a.push_back(mp[i][j]);
            sum+=(sz*(i+1));
        }
    }
    //cerr<<endl;
    sort(all(a));
    
   /* for(auto it:a) cerr<<it<<" ";
        cerr<<endl;*/
    
    string ans="";
    for(int i=0;i<a.size();i++)
        ans+=s[a[i]];
    cout<<ans;

    return 0;
    
}
