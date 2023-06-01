class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> degree(V+5,0);
	    vector<bool> visited(V+5,false);

	    for(int i=0; i<V; i++)
	    {
	        for(int node = 0; node<adj[i].size(); node++)
	        {
	            degree[adj[i][node]]++;
	        }
	    }
	   // for(int i=0; i<V; i++)
	   //     cout<<degree[i]<<" ";
	   // cout<<endl;
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(degree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int node = q.front();
	        topo.push_back(node);
	        q.pop();
	        for(int i=0; i<adj[node].size(); i++)
	        {
	            degree[adj[node][i]]--;
	            if(degree[adj[node][i]]==0)
	            {
	                q.push(adj[node][i]);
	            }
	        }
	    }
	   // for(int i=0; i<V; i++)
	   //     cout<<topo[i]<<" ";
	   // cout<<endl;
	    return topo;
	}
};
