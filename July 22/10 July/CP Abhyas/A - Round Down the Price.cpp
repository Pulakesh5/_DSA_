bool solve(){
    int num;
    cin>>num;
    int t=num,p=1;
    while(t){
        p*=10;
        t/=10;
    }
    if(p>1) p/=10;
    cout<<num-p;
    return 0;
    
}
