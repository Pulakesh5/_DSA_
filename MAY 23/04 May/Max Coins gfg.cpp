    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(), ranges.end());
        vector<int> maxEnd(n,INT_MIN);
        maxEnd[n-1]=ranges[n-1][2];
        for(int i=n-2;i>=0;i--)
            maxEnd[i]=max(maxEnd[i+1],ranges[i][2]);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            vector<int> curr=ranges[i];
            vector<int> next = {curr[1], curr[1], -1};
            int nxt = lower_bound(ranges.begin(), ranges.end(), next) - ranges.begin();
            if(nxt<=i) nxt = i+1;
            int val = curr[2];
            if(nxt<n && nxt>i) val+=maxEnd[nxt];
            ans=max(ans,val);
        }
        
        return ans;
    }
