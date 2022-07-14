bool solve(){
    int n,m;
    cin>>n>>m;
    vector<int> work(n+1,0);
    int worker;
    for(int i=0;i<m;i++){
        cin>>worker;
        work[worker]++;
    }
    /*for(auto it:work) cerr<<it<<" ";
    cerr<<endl;
    */
    int l=1,r=m,mid,ans=m,unallocated;
    while(l<r){
        mid=l+(r-l)/2;
        unallocated=0;
        for(int i=1;i<=n;i++){
            if(work[i]>=mid){
                unallocated+=((work[i]-mid));
            }
            else{
                unallocated-=((mid-work[i])/2);
            }
        }
        //cerr<<"("<<l<<", "<<r<<", "<<mid<<", "<<unallocated<<")\n";
        if(unallocated<=0){
            r=mid;
            ans=min(ans,mid);
        }
        else{
            l=mid+1;
        }
    }
    
    cout<<ans;
    
    return 0;
    
}
