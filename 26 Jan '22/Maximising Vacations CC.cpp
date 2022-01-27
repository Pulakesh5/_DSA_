//Use basic concept of DP not recursive
bool solve(){
    int n,x;
    cin>>n>>x;
    string str;
    cin>>str;
    str=str+'1';
    int zero=0;
    vector<int> holiday;
    for(int i=0;i<n+1;i++){
        if(str[i]=='1')
        {
            holiday.push_back(zero);
            zero=0;
        }
        else
            zero++;
    }
    int ans=0;
    for(auto it:holiday){
        ans+=(it/x);
    }
    //cerr<<'\n';    
    for(int i=0;i<holiday.size()-1;i++){
        if((holiday[i]+holiday[i+1]+1)/x > (holiday[i]/x + holiday[i+1]/x))
        {
            cout<<ans+1;
            return 0;
        }
    } 
    cout<<ans;
    return 0;    
}
