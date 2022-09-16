    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<int,int>>> adj(n+1);
        vector<ll> dist(n+1,1e18);
        
        int m=roads.size();
        for(int i=0;i<m;i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        
        pq.push({0,0});//{time, node}
        dist[0]=0;
        
        long long ans=0,mod=1e9+7;
        while(!pq.empty())
        {
            ll timeTillNow=pq.top().first,currNode=pq.top().second;
            pq.pop();
            
            for(pair<ll,ll> nextNode:adj[currNode])
            {
                ll timeNext = timeTillNow+nextNode.second;
                if(nextNode.first==(n-1))
                {
                    if(dist[nextNode.first]>timeNext)
                    {
                        dist[nextNode.first]=timeNext;
                        ans=0;
                    }
                    if(dist[nextNode.first]==timeNext)
                    {
                        ans=(ans+1)%mod;
                        continue;
                    }
                }
                
                if(dist[nextNode.first]>=timeNext)
                {
                    dist[nextNode.first]=timeNext;
                    pq.push({dist[nextNode.first],nextNode.first});
                }
            }
        }
        return ans;
    }
