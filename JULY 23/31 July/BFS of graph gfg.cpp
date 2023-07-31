class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int k=0;
        vector<int> bfsTraversal, visited(V);
        
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty())
        {
            int node = q.front();
            bfsTraversal.push_back(node);
            q.pop();
            for(int child:adj[node])
            {
                if(visited[child]==0)
                {
                    visited[child] = 1;
                    q.push(child);
                }
            }
        }
        
        return bfsTraversal;
    }
};
