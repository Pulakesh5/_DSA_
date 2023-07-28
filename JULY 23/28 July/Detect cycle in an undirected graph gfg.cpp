    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V+5, false);
        pair<int,int> pr;
        int vertice, parent;
        
        for(int v=0; v<V; v++)
        {
            if(!visited[v])
            {
                queue<pair<int,int>> q;
                q.push({v,-1});
                visited[v] = true;
                while(!q.empty())
                {
                    pr = q.front();
                    q.pop();
                    vertice = pr.first;
                    parent = pr.second;
                    for(int next:adj[vertice])
                    {
                        if(!visited[next])
                        {
                            q.push({next,vertice});
                            visited[next] = true;
                        }
                        else if(next!=parent)
                            return true;
                    }
                }
            }
        }
        return false;
    }
