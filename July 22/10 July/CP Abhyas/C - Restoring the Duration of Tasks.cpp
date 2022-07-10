bool solve(){
    int n;
    cin>>n;
    vector<int> start(n),finish(n);
    
    input(start,n);
    input(finish,n);
    
    int last_task=-1;
    for(int i=0;i<n;i++){
        cout<<finish[i] - max(last_task,start[i])<<" ";
        last_task=finish[i];
    }
    
    return 0;
    
}
