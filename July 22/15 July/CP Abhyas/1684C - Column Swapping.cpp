bool solve(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> a(r,vector<int> (c));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cin>>a[i][j];
    }
    vector<int> v;
    set<int> st;
    for(int i=0;i<r && st.size()<=2;i++){
        v=a[i];
        sort(all(v));
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=v[j])
            st.insert(j);
        }
    }
    
    if(st.size()>2){
        cout<<-1;
        return 0;
    }
    else if(st.size()==0){
        cout<<1<<" "<<1;
        return 0;
    }
    else{
        auto it=st.begin();
        int ind1=*it,ind2=*(++it);
        for(int i=0;i<r;i++){
            v=a[i];
            sort(all(v));
            if(v[ind2]!=a[i][ind1] || v[ind1]!=a[i][ind2]){
                cout<<-1;
                return 0;
            }
        }   
        cout<<ind1+1<<" "<<ind2+1;
    }
    return 0;
    
}
