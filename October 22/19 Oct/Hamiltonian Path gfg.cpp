    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int node, int Count)
    {
        if(Count==0) return true;
        visited[node]=true;
        for(int nbr:adj[node])
        {
            if(!visited[nbr])
                if( dfs(adj,visited,nbr,Count-1))
                    return true;
        }
        visited[node]=false;
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>> adj(N);
        
        for(auto edge:Edges)
        {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        vector<bool> visited(N,0);
        int Count=N-1,node;
        for(int i=0;i<N;i++)
        {
            node=i;
            if(dfs(adj,visited,node,Count))
                return true;
        }
        return false;
    }
