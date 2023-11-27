class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    parent.resize(V,-1);
	    for(int i=0; i<V; i++)
	        parent[i] = i;
	    for(int v=0; v<V; v++)
	    {
	        for(int next:adj[v])
	        {
	            if(next<v)
	                continue;
	            if(find(v)==find(next))
	                return true;
	            _union(v, next);
	        }
	    }
	    return 0;
	}
	private:
	vector<int> parent;
	int find(int u)
	{
	    if(u != parent[u])
	        parent[u] = find(parent[u]);
	    return parent[u];
	}
	void _union(int u, int v)
	{
	    int u_root = find(u);
	    int v_root = find(v);
	    if(u_root != v_root)
	        parent[v_root] = u_root;
	}
};
