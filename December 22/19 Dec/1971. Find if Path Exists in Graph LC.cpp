class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n+5];
        vector<int> visited(n+5,0);
        
        for(auto v:edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        queue<int> q;
        visited[source]=1;
        q.push(source);

        while(!q.empty())
        {
            int vertex=q.front();
            q.pop();
            if(vertex==destination) return true;
            for(auto ne:adj[vertex])
            {
                if(!visited[ne]) 
                {
                    q.push(ne);
                    visited[ne]=1;
                }
            }
        }

        return false;
    }
};
