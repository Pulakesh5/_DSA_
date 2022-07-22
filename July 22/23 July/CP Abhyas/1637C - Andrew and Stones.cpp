bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    input(a,n);
    int count=0;
    bool flag=false;
    for(int i=1;i<(n-1);i++)
    {
        if(a[i]>1) flag=true;
        count+=(a[i]+1)/2;
    }
    if(!flag || (n==3 && (a[1]&1))) cout<<-1;
    else cout<<count;
 
 
    return 0;
}
