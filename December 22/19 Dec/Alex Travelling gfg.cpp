    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<int> Cost(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto v:flights)
        {
            adj[v[0]].push_back({v[1],v[2]});
        }
        Cost[k]=0;
        queue<int> q;
        q.push(k);
        
        while(!q.empty())
        {
            int city=q.front();
            q.pop();
            for(auto pr:adj[city])
            {
                if(Cost[pr.first] > (Cost[city]+pr.second))
                {
                    q.push(pr.first);
                    Cost[pr.first]=Cost[city]+pr.second;
                }
            }
        }
        
        int maxCost=0;
        for(int i=1;i<=n;i++) maxCost=max(maxCost,Cost[i]);
        return (maxCost==1e9?-1:maxCost);
        
    }
