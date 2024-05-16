class Solution {
private: 
    int traverse(vector<vector<int>> &adjMatrix, vector<bool> &visited, int root, int &edgeRemoved)
    {
        int countOfNodes=1;
        visited[root] = 1;
        
        for(auto child:adjMatrix[root])
        {
            if(visited[child])
                continue;
            countOfNodes+=traverse(adjMatrix, visited, child, edgeRemoved);
        }
        // cout<<root<<" : "<<countOfNodes<<endl;
        if(countOfNodes%2==0 && root!=1) 
        {
            edgeRemoved++;
            return 0;
        }
        return countOfNodes;
        
    }
public:
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<vector<int>> adjMatrix(n+5);
	    vector<bool> visited(n+5,0);

	    for(auto edge:edges)
	    {
	        adjMatrix[edge[0]].push_back(edge[1]);
	        adjMatrix[edge[1]].push_back(edge[0]);
	    }

	    int root = 1, edgeRemoved = 0;
	    traverse(adjMatrix, visited, root, edgeRemoved);
	    return edgeRemoved;
	}
};
