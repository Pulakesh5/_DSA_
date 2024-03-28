class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
 
        for( int i = 0; i < m; i++ )
        {
        adj[edges[i][0]].push_back({edges[i][2], edges[i][1]});
        adj[edges[i][1]].push_back({edges[i][2], edges[i][0]});
        }
 
        for(int i = 0; i < n; i++)
        {    
        
        pq.push({0,i});
        dist[i][i] = 0;
        while(pq.size())
        {
        auto temp = pq.top();
        pq.pop();
        int distance = temp.first;
        int node = temp.second;
        for(auto it : adj[node])
        {
        if( distance + it.first < dist[i][it.second] )
        {
        dist[i][it.second] = distance + it.first;
        pq.push({dist[i][it.second], it.second});
        }
        }
        }
        }
 
        int countMax = INT_MAX;
        int city = -1;
 
        for( int i = 0; i < n; i++ )
        {
            int count = 0;
        for(int j = 0; j < n; j++)
        {
        if(dist[i][j] <= distanceThreshold)
        {
        count++;
        }
        }
        if(count <= countMax)
        {
        countMax = count;
        city = i;
        }
        }
 
        return city;
    }
};
