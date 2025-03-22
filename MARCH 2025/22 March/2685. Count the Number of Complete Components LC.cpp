class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n);
        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        int ConnectedComponent = 0;
        for(int i=0; i<n; i++)
        {
            if(visited[i])
                continue;
            q.push(i);
            visited[i] = true;
            int NoOfNodes = 0, NoOfEdges = 0;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                NoOfNodes++;
                // cout<<node<<endl;
                for(int next:adj[node])
                {
                    NoOfEdges++;
                    if(visited[next])
                        continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            // cout<<NoOfNodes<<" "<<NoOfEdges<<endl;
            ConnectedComponent+=(NoOfEdges == (NoOfNodes*(NoOfNodes-1)));
        }
        return ConnectedComponent;
        
    }
};
