class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V+5);
        
        for(int v=0; v<V; v++)
        {
            vector<int> vec=adj[v];
            for(int u:vec)
                inDegree[u]++;
        }
        
        queue<int> q;
        
        for(int v=0; v<V; v++)
        {
            if(inDegree[v]==0)
                q.push(v);
        }
        int encountered = 0;
        while(!q.empty())
        {
            int vertice = q.front();
            q.pop();
            encountered++;
            for(int v:adj[vertice])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                    q.push(v);
            }
        }
        return encountered!=V;
    }
};
