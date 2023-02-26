    void isConnected(int node, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &adjNodes)
    {
        adjNodes.push_back(node);
        visited[node]=true;
        
        for(int it:adjList[node])
        {
            if(!visited[it])
                isConnected(it, adjList, visited, adjNodes);
        }
        
    }
    
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adjList) {
        // code here
        vector<bool> visited(V+1,false);
        
        bool flag=true;
        int connectedComponents=0;
        
        for(int i=1;i<=V;i++)
        {
            if(!visited[i])
            {
                flag=true;
                vector<int> adjNodes;
                isConnected(i, adjList, visited, adjNodes) ;
                
                for(int node=0;node<adjNodes.size();node++)
                {
                    if(adjNodes.size()-1>adjList[adjNodes[node]].size())
                    {
                        flag=false;
                        break;
                    }
                }
                connectedComponents+=flag;
            }
        }
        return connectedComponents;
    }
