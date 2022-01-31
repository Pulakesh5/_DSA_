// Solution Idea:   pair consecutive numbers but if any a_i makes lesser xor with 0 than a_(i-1)
//                  swap 0 and a[i-1] 
//                  there is no proof currently
bool solve(){
    int n;
    cin>>n;
    vector<int> ans(n,0);
    ans[0]=0;ans[1]=1;
    int zero=0;
    for(int i=2;i<n;i++){
        if((0^i) < (ans[i-1]^i)){
            ans[zero]=ans[i-1];
            ans[i-1]=0;
            zero=i-1;
        }
        ans[i]=i;
    }
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
 
}
