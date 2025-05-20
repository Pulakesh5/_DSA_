class Solution {
    class Edge{
        int dest, weight;
        public Edge(int _dest, int _weight)
        {
            this.dest = _dest;
            this.weight = _weight;
        }
    }
    
    void topoSort(ArrayList<ArrayList<Edge>> adj, int node, boolean[] visited, Stack<Integer> stk)
    {
        visited[node] = true;

        for(Edge edge:adj.get(node))
        {
            if(visited[edge.dest])
                continue;
            topoSort(adj, edge.dest, visited, stk);
        }

        stk.push(node);
    }
    
    public int[] shortestPath(int V, int E, int[][] edges) {
        // Code here
        
        ArrayList<ArrayList<Edge>> adj = new ArrayList<>();
        for(int i=0; i<V; i++)
            adj.add(new ArrayList<Edge>());
        
        for(int[] edge:edges) // edge[0] = source, edge[1] = destination, edge[2] = weight
        {
            adj.get(edge[0]).add(new Edge(edge[1], edge[2]));
        }
        
        boolean[] visited = new boolean[V];
        Stack<Integer> stk = new Stack<>();
        
        for(int i=0; i<V; i++)
        {
            if(visited[i])
                continue;
            topoSort(adj, i, visited, stk);
        }
        
        int[] distance = new int[V];
        int INF = 1000000000;
        Arrays.fill(distance, INF);
        int src = 0;
        distance[src] = 0;
        
        while(!stk.isEmpty())
        {
            int node = stk.pop();
            if(distance[node]!=INF)
            {
                for(Edge edge:adj.get(node))
                {
                    if(distance[node]+edge.weight < distance[edge.dest])
                        distance[edge.dest] = distance[node]+edge.weight;
                }
            }
        }
        
        for(int i=0; i<V; i++)
            distance[i] = ((distance[i]==INF)?-1:distance[i]);
        
        return distance;
    }
}
