bool solve(){
    string s;
    cin>>s;
    int n=s.length(),ans=0;
    set<char> st;
    
    for(int i=0;i<n;i++){
        if(st.find(s[i])==st.end())
            st.insert(s[i]);
        if(st.size()>3){
            st.clear();
            st.insert(s[i]);
            ans++;
        }
    }
    if(st.size()>0) ans++;
    cout<<ans;
    
    return 0;
    
}
