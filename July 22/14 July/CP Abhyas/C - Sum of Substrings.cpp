bool solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0,oneCount=0,lastOne=-1,firstOne=-1;
    
    for(int i=0;i<n;i++){
        if(s[i]=='0') continue;
        oneCount++;
        if(firstOne==-1) firstOne=i;
        lastOne=i;
    }
    //cerr<<firstOne<<" "<<lastOne<<'\n';
    int lastNotDone=1;
    if(lastOne!=-1 && (n-1-lastOne)<=k){
        oneCount--;
        k-=(n-1-lastOne);
        lastNotDone=0;
        ans+=1;   
    }
    if(firstOne!=-1 && (lastNotDone==1 || firstOne!=lastOne) && firstOne<=k){
        oneCount--;
        k-=firstOne;
        ans+=10;
    }
    ans+=(oneCount*11);
    cout<<ans;
    
    return 0;
    
}
