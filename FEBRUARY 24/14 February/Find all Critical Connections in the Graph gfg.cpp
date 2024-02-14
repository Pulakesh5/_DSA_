int DFS(int node, int parent, int rank, vector<int> &nodeRanks, vector<bool> &visited, vector<vector<int>> &criticalEdges, vector<int> adj[])
{
    nodeRanks[node] = rank;
    visited[node] = true;
    
    int minDepth = INT_MAX, minRank = INT_MAX;
    for(int next:adj[node])
    {
        if(next!=parent)
        {
            if(visited[next])
                minDepth = min(minDepth, nodeRanks[next]);
            else
            {
                minRank = DFS(next, node, rank+1, nodeRanks, visited, criticalEdges, adj);
                
                if(nodeRanks[node]<minRank)
                    criticalEdges.push_back({node,next});
                minDepth = min(minDepth, minRank);
            }
        }
    }
    return minDepth;
}

class Solution {
public:
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<int> nodeRanks(v+5,-1);
	    vector<bool> visited(v+5,false);
	    vector<vector<int>> criticalEdges;
	    int node=0, parent=-1, rank=1;
	    DFS(node, parent, rank, nodeRanks, visited, criticalEdges, adj);
	    
	    for(int i=0; i<criticalEdges.size(); i++)
	        sort(criticalEdges[i].begin(),criticalEdges[i].end());
	    
	    sort(criticalEdges.begin(), criticalEdges.end());
	    
	    return criticalEdges;
	}
};
