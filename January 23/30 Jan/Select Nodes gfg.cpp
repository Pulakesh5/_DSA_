    int count=0;
    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int node)
    {
        visited[node] = true;
        bool selected = false;
        for(int child:adj[node])
        {
            if(!visited[child])
            {
                bool childSelected = dfs(adj, visited, child);
                if(!childSelected)
                    selected = true; 
            }
        }
        count+=(selected);
        return selected;
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<vector<int>> adj(N);
        for(vector<int> edge:edges)
        {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        vector<bool> visited(N+1,false);
        dfs(adj, visited, 0);
        return count;
    }
