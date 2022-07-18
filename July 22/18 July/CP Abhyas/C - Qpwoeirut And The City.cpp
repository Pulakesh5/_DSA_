pair<int,int> rec(int index, vector<int> &a, vector<pair<int,int>> &dp){
    if(index>=(a.size()-1)) return {0,0};
    
    if(dp[index].first!=-1) return dp[index];
    
    pair<int,int> ans1 = rec(index+1,a,dp);
    pair<int,int> ans2 = rec(index+2,a,dp);
    
    ans2.first++; // ans2.first + curent index
    ans2.second+= max(max(a[index-1],a[index+1])-a[index]+1,0ll);
    
    if(ans2.first==ans1.first)
        dp[index] = {ans2.first, min(ans2.second,ans1.second)};
    else{
        if(ans2.first>ans1.first)
            dp[index]=ans2;
        else
            dp[index]=ans1;
    }
    
    return dp[index];   
}
bool solve(){
    int n,k;
    cin>>n;
    vector<int> a(n);
    input(a,n);
    vector<pair<int,int>> dp(n,{-1,-1});
    
    cout<<rec(1,a,dp).second;
    return 0;
}
