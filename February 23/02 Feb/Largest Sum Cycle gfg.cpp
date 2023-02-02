  long long longestCycle=-1;
  void DFS(int node, vector<int> &Edge, vector<bool> &visited, vector<bool> &pathVisited)
  {
        visited[node]=true;
        pathVisited[node]=true;
        int adj;
        if(Edge[node]!=-1)
        {
            adj = Edge[node];
            if(!visited[adj])
            {
                DFS(adj,Edge,visited,pathVisited);
            }
            else if(pathVisited[adj])
            {
                long long length = 0;
                long long curr=adj;
                do{
                    length+=curr;
                    curr=Edge[curr];
                }while(adj!=curr);
                
                longestCycle=max(longestCycle,length);
            }
        }
        pathVisited[node]=false;
  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
        vector<bool> visited(N,false), pathVisited(N,false);
        for(int i=0;i<N;i++)
        {
            if(!visited[i])
                DFS(i,Edge,visited,pathVisited);
        }
        return longestCycle;
  }
