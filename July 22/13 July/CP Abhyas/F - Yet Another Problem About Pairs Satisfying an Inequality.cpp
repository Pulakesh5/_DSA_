bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    input(a,n);
    vector<int> arr,pos;
    for(int i=0;i<n;i++){
        if(a[i]<(i+1)){
            arr.push_back(a[i]);
            pos.push_back(i+1);
        }
    }
    
    sort(all(arr));
    sort(all(pos));

    int ans=0;
    for(auto p:pos){
        //auto count = lower_bound(all(arr),p+1) - arr.begin();//
        auto count = arr.end() - upper_bound(all(arr),p);
        //count= arr.size() - count;
        ans+= count;
    }
    cout<<ans;
    return 0;
    
}
