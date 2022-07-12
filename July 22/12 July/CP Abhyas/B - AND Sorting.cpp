bool solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    input(a,n);
    b=a;
    sort(all(b));
    vector<int> bits(20,0);
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            for(int b=0;b<20;b++) 
                if(a[i]&(1<<b)) bits[b]++;
            count++;
        }
    }
    int ans=0;
    for(int i=0;i<20;i++){
        if(bits[i]==count) ans+=(1<<i);
    }
    cout<<ans;
    return 0;
    
}
