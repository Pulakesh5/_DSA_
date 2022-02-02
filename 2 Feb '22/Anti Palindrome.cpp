//Time Complexity : O(n)
//Space Complexity: O(1)
bool ispal(string str, int n){
    if(n%2==1)
        return true;
    int l=0,r=n-1;
    while(l<=r){
        if(str[l]==str[r])
            return true;
        l++;r--;
    }
    return false;
}
bool solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    sort(all(str));
    int d=cl(n,2);
    reverse(str.begin(),str.begin()+d);
    bool flag=ispal(str,n);
    if(!flag){
        cout<<"YES\n";
        cout<<str;
    }
    else
        cout<<"NO";
    

    
    return 0;
}
