class Solution {
  public:
    bool check(int node, vector<int> adj[], vector<int> &color)
    {
        if(color[node] != 0)
            return color[node] == 2;
        color[node] = 1;
        for(int next:adj[node])
        {
            if(color[next]==1 || (color[next]!=2 and !check(next, adj, color)))
                return false;
        }
        color[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> color(V, 0);
        color[0] = 0;
        
        check(0, adj, color);
        
        vector<int> safeNodes;
        
        for(int i=0; i<V; i++)
        {
            if(check(i, adj, color))
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
