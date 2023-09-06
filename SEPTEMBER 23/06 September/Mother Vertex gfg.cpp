class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> adj[], vector<bool> &visited, int node)
    {
        visited[node] = true;
        for(int next:adj[node])
        {
            if(!visited[next])
                dfs(adj, visited, next);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> visited(V, false);
	    int qs, lastVisited;
	    for(int i=0; i<V; i++)
	    {
	        if(!visited[i])
	        {
	           // cout<<"Entered for "<x<i<<endl;
	            queue<int> q;
	            q.push(i);
	            visited[i] = true;
	            while(!q.empty())
	            {
	                qs = q.size();
    	            for(int j=0; j<qs; j++)
    	            {
    	                int node = q.front();
    	                q.pop();
    	                for(int next:adj[node])
    	                {
    	                    if(!visited[next])
    	                    {
    	                        visited[next] = true;
    	                        q.push(next);
    	                    }
    	                }
    	            }   
	            }
	            lastVisited = i;
	        }
	    }
	   // cout<<lastVisited<<endl;
	    
	    fill(visited.begin(), visited.end(), false);
	    dfs(adj, visited, lastVisited);
	    
	    for(int i=0; i<V; i++)
	    {
	        if(!visited[i])
	            return -1;
	    }
	    
	    return lastVisited;
	    
	}

};
