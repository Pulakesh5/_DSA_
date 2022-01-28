bool solve(){
    int n,x;
    cin>>n>>x;
    
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
   {
        cin>>a[i];b[i]=a[i];
    }
    sort(all(b));
    if(n>=2*x)
        cout<<"YES";
    else{
        for(int i=n-x;i<x;i++){
            if(a[i]!=b[i])
            {
                cout<<"NO";
                return 0;
            }    
        }
        cout<<"YES";
    }
    return 0;
}
