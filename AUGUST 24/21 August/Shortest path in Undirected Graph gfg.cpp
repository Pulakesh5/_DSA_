class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> adjList(N);
        for(auto edge:edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> distance(N,N+1);
        vector<bool> visited(N,false);
        queue<int> q;
        q.push(src);
        visited[src] = true;
        int dist = 0;
        while(!q.empty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                int node = q.front();
                q.pop();
                distance[node] = dist;
                for(int next:adjList[node])
                {
                    if(!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            dist++;
        }
        for(int i=0; i<N; i++)
        {
            if(distance[i]==(N+1))
                distance[i] = -1;
        }
        return distance;
    }
};
