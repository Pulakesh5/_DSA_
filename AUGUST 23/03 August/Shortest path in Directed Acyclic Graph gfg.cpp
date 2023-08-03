class Solution {
  public:
    const int INF = 1e9+7;  
    int findMin(vector<int> &distance, vector<bool> &visited)
    {
        int V = distance.size(), minIndex, minDistance = INT_MAX;
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i] && distance[i]<=minDistance)
            {
                minDistance = distance[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> distance(N,INF);
        vector<bool> visited(N);
        vector<vector<int>> adj(N,vector<int>(N,0));
        
        for(vector<int> edge:edges)
        {
            adj[edge[0]][edge[1]] = edge[2];
        }
        
        distance[0] = 0;
        int u;
        for(int count = 0; count<(N-1); count++)
        {
            u = findMin(distance, visited);
            visited[u] = true;
            for(int v=0; v<N; v++)
            {
                if(!visited[v] && adj[u][v] && distance[u]!=INF && distance[u]+adj[u][v]<distance[v])
                    distance[v] = distance[u]+adj[u][v];
            }
        }
        for(int i=0; i<N; i++)
            distance[i] = (distance[i]==INF) ? -1:distance[i];
        return distance;
    }
};
