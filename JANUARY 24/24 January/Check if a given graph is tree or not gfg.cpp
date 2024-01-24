class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        if(n==1 && m==0)
            return 1;
        if(m!=(n-1))
            return 0;
        vector<vector<int>> adjList(n+5);
        for(vector<int> edge:adj)
        {
            if(edge[0]!=edge[1])
            {
                adjList[edge[0]].push_back(edge[1]);
                adjList[edge[1]].push_back(edge[0]);
            }
            else
                return 0;
        }
        vector<int> visited(n+5);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int visitedCount = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visitedCount++;
            for(auto next:adjList[node])
            {
                if(visited[next]==0)
                {
                    q.push(next);
                    visited[next] = 1;
                }
            }
        }
        if(visitedCount==n)
            return 1;
        return 0;
    }
};
