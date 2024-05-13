class Solution {
    private:
    bool goodComponent(vector<vector<int>> &adj, vector<int> &degree, vector<bool> &visited, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        set<int> visitedNode;
        visitedNode.insert(node);
        int componentSize=1;
        while(!q.empty())
        {
            int curNode = q.front();
            q.pop();
            for(auto next:adj[curNode])
            {
                if(visited[next]==0)
                {
                    componentSize++;
                    visitedNode.insert(next);
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
        for(auto it:visitedNode)
        {
            if(degree[it]!=(componentSize-1))
                return false;
        }
        return true;
    }
    public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<int> degree(v+5,0);
        vector<vector<int>> adj(v+2);
        for(auto edge:edges)
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(v+5, 0);
        int numberOfGoodComponent=0;
        for(int i=1; i<=v; i++)
        {
            if(visited[i]==0 && goodComponent(adj, degree, visited, i))
            {
                numberOfGoodComponent++;
            }
        }
        
        return numberOfGoodComponent;
    }
};
