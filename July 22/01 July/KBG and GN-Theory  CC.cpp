bool solve(){
    int n,q;
    cin>>n>>q;
    int a,b;
    
    while(q--){
        cin>>a>>b;
        int gc=gcd(a,b);
        int ans=0;
        a/=gc;
        b/=gc;
        
        for(int x:{a,b}){
            int i=2;
            while(x%i==0){
                ans+=i;
                x/=i;
            }
            for(i=3;i*i<=x;i+=2){
                while(x%i==0){
                    ans+=i;
                    ans/=i;
                }
            }
            if(x>1) ans+=x;
        }
        
        cout<<ans<<endl;;
    }
    return 0;
}
