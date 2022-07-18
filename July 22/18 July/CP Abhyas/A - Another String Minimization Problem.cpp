bool solve(){
    int n,m,ans;
    cin>>n>>m;
    vector<int> a(n);
    input(a,n);
    
    string s(m,'B');
    
    for(int i=0;i<n;i++){
        if(s[a[i]-1]=='B' && s[m-a[i]]=='B')
            s[min(a[i],m+1-a[i])-1]='A';
        else if(s[a[i]-1]=='B')
            s[a[i]-1]='A';
        else
            s[m-a[i]]='A';
    }
    
    cout<<s;
    
    
    return 0;
    
}
