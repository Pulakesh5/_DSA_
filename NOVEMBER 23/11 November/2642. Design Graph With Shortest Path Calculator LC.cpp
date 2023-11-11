#define pi pair<int, int>
class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) {
        nodeCount = n;
        adjList.resize(nodeCount);
        for(vector<int> edge:edges)
            adjList[edge[0]].push_back({edge[1], edge[2]});
    }
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }
    int shortestPath(int node1, int node2) {
        vector<int> visited(nodeCount, INT_MAX);
        if(node1==node2)
            return 0;
        queue<pi> q;
        for(pi edge:adjList[node1])
        {
            q.push({edge.first, edge.second});
            visited[edge.first] = edge.second;
        }
        int next, cost, minCost = INT_MAX;
        while(!q.empty())
        {
            pi node = q.front();
            next = node.first;
            cost = node.second;
            q.pop();
            if(next==node2)
                minCost=min(minCost, cost);
            for(pi edge:adjList[next])
            {
                if(visited[edge.first]>cost+edge.second)
                {
                    visited[edge.first] = cost+edge.second;
                    q.push({edge.first, cost+edge.second});
                }
            }
        }
        cout<<endl; 
        return ((minCost==INT_MAX) ? -1: minCost);
    }

private:
    int nodeCount=100;
    vector<vector<pi>> adjList;
};
