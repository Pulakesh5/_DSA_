class Solution {
public:     
    int componentCount = 0;
    int traverse(vector<vector<int>> &adjList, vector<int> &values, int &k, int node, vector<int> &visited)
    {
        int treeSum = 0;
        visited[node] = 1;
        for(int next:adjList[node])
        {
            if(!visited[next])
                treeSum += traverse(adjList, values, k, next, visited);
        }
        treeSum += values[node];
        if(treeSum%k == 0)
            componentCount++;
        return treeSum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adjList(n);
        vector<int> visited(n);
        for(auto edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        traverse(adjList, values, k, 0, visited);
        return componentCount;
    }
};
