/*
Solution Idea:
              req[i] = s[i]-'0' + 10*m
              req is a non increasing sequence
              O(n) or O(nlogn)
*/
bool solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    for(int i=0;i<n;i++){
        
        int req=(s[i]-'0');
        if(req+k<10)
            break;
        k = 10 - req + ((k -(10- req))/ 10)*10;
        s[i]='0';
    }
    int ans = 0;
    int i=0;

    while(i<n) {
        //cerr<<s[i];
        if (s[i++] != '0') break;
        ans++;
    }
    cout<<ans;
    
    return 0;
}
