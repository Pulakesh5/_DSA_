bool isSorted(vector<int> a){
    for(int i=0;i<(a.size()-1);i++)
        if(a[i]>a[i+1]) return false;
    
    return true;
}
 
bool solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    input(a,n);
    input(b,n);
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(make_pair(a[i],b[i])>make_pair(a[j],b[j])){
                swap(a[i],a[j]);
                swap(b[i],b[j]);
                ans.push_back({i+1,j+1});
            }
        }
    }
    if(!(isSorted(a) && isSorted(b)))
    {
        cout<<-1<<'\n';
        return 0;
    }
    cout<<ans.size()<<'\n';
    for(auto it:ans)
        cout<<it.first<<" "<<it.second<<'\n';
    
    return 0;
    
}
