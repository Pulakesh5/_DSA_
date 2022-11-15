    int beautySum(string s) {
        // Your code goes here
        int n=s.length();
        
        int ans=0;
        
        for(int i=0;i<(n);i++)
        {
            vector<int> mp(26,0);
            
            for(int j=i;j<n;j++)
            {
                mp[s[j]-'a']++;
                int mn,mx;
                mn=INT_MAX;
                mx=0;
                for(int k=0;k<26;k++)
                {
                    
                    if(mp[k]>0)
                        mn=min(mn,mp[k]);
                    mx=max(mx,mp[k]);
                }
                ans+=(mx-mn);
            }
        }
    
        return ans;
    }
    
