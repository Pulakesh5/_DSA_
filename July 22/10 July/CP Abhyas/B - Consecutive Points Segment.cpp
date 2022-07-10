bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    
    input(a,n);
    for(int i=0;i<n;i++) a[i]-=i;
    
    vector<int> l={a[0]-1,a[0],a[0]+1};
    bool flag=true;
    for(int j=0;j<3;j++){
        flag=true;
        for(int i=0;i<n;i++){
            if(a[i]>l[j]+1 || a[i]<l[j]-1)
                flag=false;
        }
        if(flag){
            cout<<"YES";
            return 0;
        }
    }
    
    cout<<"NO";
    return 0;
    
}
