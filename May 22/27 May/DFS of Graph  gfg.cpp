class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void rec(vector<int> adj[], vector<int> &dfs, vector<bool> &visited, int node){
        visited[node]=1;
        dfs.push_back(node);
        for(auto it:adj[node])
        {
            if(!visited[it])
                rec(adj,dfs,visited,it);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        
        vector<int> dfs;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                rec(adj,dfs,visited,i);
            }
        }
        return dfs;
    }
    
};
