bool solve(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    if((a+b)>=max(a,b)) cout<<n*(a+b);
    else{
        int ans=INT_MIN;
        int onezero=0,zeroone=0;
        for(int i=1;i<n;i++){
            if(s[i-1]=='1'&&s[i]=='0') onezero++;
        }
        zeroone=onezero;
        if(s[n-1]=='1') onezero++;
        if(s[0]=='0') zeroone++;
        if(zeroone>0) ans=b*(onezero+1);
        if(onezero>0) ans=max(ans,b*(zeroone+1));
        cout<<n*a+max(n*b,ans);
    }
    return 0;
    
}
