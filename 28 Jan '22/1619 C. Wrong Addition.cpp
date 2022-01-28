bool solve(){
    string a,s;
    string ans="";
    cin>>a>>s;
    reverse(all(a));
    reverse(all(s));
    int la=a.length(),ls=s.length();
    if(la>ls)
    {
        cout<<-1;
        return 0;
    }
    //int n=min(la,ls);
    int i=0,j=0;
    for( ;i<la && j<ls;i++,j++){
        int da=a[i]-'0',ds=s[j]-'0';
        if(ds-da>=0)
            ans+=(char)((ds-da)+'0');
        else{
            if(j+1<ls && s[j+1]=='1')
            {
                ans+=(char)((ds-da+10)+'0');
                j++;
            }
            else
            {
                cout<<-1;
                return 0;
            }     
        }
    }
    if(i!=la){
        cout<<-1;
        return 0;
    }
    while(j<ls){
        ans+=s[j];
        j++;
    }
    //reverse(all(ans));
    while(ans.back()=='0')
        ans.pop_back();
    reverse(all(ans));
    cout<<ans;
    
    return 0;
}
