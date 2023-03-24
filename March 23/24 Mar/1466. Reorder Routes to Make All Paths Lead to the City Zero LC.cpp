class Solution {
public:
    void dfs(vector<vector<int>> &adj, set<vector<int>> &edges, int src, int parent, int &reorder)
    {
        for(auto i:adj[src])
        {
            if(i!=parent)
            {
                if(edges.find({src,i})!=edges.end())
                    reorder++;
                dfs(adj, edges, i, src, reorder);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<vector<int>> edges;
        for(auto conn:connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
            edges.insert(conn);

        }
        int reorder=0;
        dfs(adj,edges,0,-1,reorder);
        return reorder;
    }
};
