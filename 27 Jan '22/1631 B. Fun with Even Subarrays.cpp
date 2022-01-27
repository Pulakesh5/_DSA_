//take subarrays which has same nums as last element and greedily go towards start
bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int last=a[n-1];
    int ans=0,pos=n-1,size;
    while(pos>=0){
        if(a[pos]!=last)
        {
            size=n-1-pos;
            pos-=size;
            ans++;
        }
        else
            pos--;
    }
    cout<<ans;
    
    return 0;
}
