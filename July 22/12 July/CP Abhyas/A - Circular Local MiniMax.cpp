bool solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    input(a,n);
    sort(all(a));
    if((n%2)==1) cout<<"NO";
    else if(a[n/2-1]!=a[n/2]){
        cout<<"YES\n";
        vector<int> ans(n);
        int j=0;
        for(int i=0;i<n;i+=2)
            ans[i]=a[j++];        
        for(int i=1;i<n;i+=2)
            ans[i]=a[j++];
        for(auto it:ans) cout<<it<<" ";
    }
    else{
        int l=n/2-1,r=n/2;
        
        while(l>=0 && a[l]==a[n/2-1]) l--;
        while(r<n && a[r]==a[n/2]) r++;
        
        int left=(n/2-l-1),right=r-n/2,half=n/2;
        //cerr<<left<<" "<<right<<"\n";
        if((left+right+1)<=half){
            cout<<"YES\n";
            vector<int> ans(n);
            int j=0;
            for(int i=0;i<n;i+=2)
                ans[i]=a[j++];    
            for(int i=1;i<n;i+=2)
                ans[i]=a[j++];
            for(auto it:ans) cout<<it<<" ";
        } 
        else
            cout<<"NO";
    }
    
    
    return 0;
    
}
