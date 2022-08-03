
bool solve(){
    int x,y;
    cin>>x>>y;
    pair<int,int> p1,p2;
    
    for(int d=sqrt(y);d>0;d--){
        if((y%d)==0){
            p1.first=d;
            p1.second=y/d;
            break;
        }
    }
    p2.ff=x/2ll;
    p2.ss=x-p2.ff;
    if(p1.ff>p2.ss || p1.ss < p2.ff){
        cout<<p1.ff<<" "<<p1.ss<<endl;
        cout<<p2.ff<<" "<<p2.ss;
    }
    else
        cout<<-1;
    
    return 0;
}
