    int maximizeSum(int a[], int n) 
    {
        map<int,int, greater<int>> mp;
        for(int i=0;i<n;i++) mp[a[i]]++;
        int sum=0;
        for(auto it:mp) 
        {
            if(it.second==0) continue;
            sum+=(it.first*it.second);
            if(mp.find(it.first-1)!=mp.end() && mp[it.first-1]>0) 
                mp[it.first-1]-=min(mp[it.first-1],it.second);
        }
        return sum;
    }
