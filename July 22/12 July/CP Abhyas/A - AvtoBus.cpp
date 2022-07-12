bool solve(){
    int n;
    cin>>n;
    int minAns=0,maxAns=0;
    if(n<4 || (n%2)!=0)
        cout<<-1;
    else{
        minAns=(n/6ll);
        maxAns=(n/4ll);
        if((n%6ll)!=0)
            minAns+=1;
        cout<<minAns<<" "<<maxAns;
    }
 
    return 0;
    
}
