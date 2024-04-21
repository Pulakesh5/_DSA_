class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty())
        {
            int vertex = q.front();;
            q.pop();
            if(vertex==destination)
            {
                return true;
            }
            for(auto next:adj[vertex])
            {
                if(!visited[next])
                {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        return false;
    }
};
