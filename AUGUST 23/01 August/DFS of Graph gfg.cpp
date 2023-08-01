    void dfs(int root, vector<int> adj[], vector<bool> &visited, vector<int> &traversal){
        visited[root] = true;
        traversal.push_back(root);

        for(int next:adj[root])
        {
            if(!visited[next])
                dfs(next, adj, visited, traversal);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> traversal;
        vector<bool> visited(V, false);
        dfs(0, adj, visited, traversal);
        return traversal;
    }
