class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    vector<int> visited(V,1);
	    queue<int> q;
	    q.push(0);
	    visited[0] = 0;
	    int level = 0, qs, node;
	    while(!q.empty())
	    {
	        qs = q.size();
	        for(int i=0; i<qs; i++)
	        {
	            node = q.front();
	            q.pop();
	            if(node==X)
	                return level;
	            for(int next:adj[node])
	            {
	                if(visited[next])
	                {
	                    q.push(next);
	                    visited[next] = 0;
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};
