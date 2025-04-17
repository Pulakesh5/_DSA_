class Solution {
    class Edge {
        int dest;
        int weight;
        public Edge(int d, int w)
        {
            this.dest = d;
            this.weight = w;
        }
    }
    int INFINITY = (int)(1e9);
    int RunDijkstra(int src, int dest, ArrayList<ArrayList<Edge>> adjMatrix)
    {
        int V = adjMatrix.size();
        PriorityQueue<Edge> pq = new PriorityQueue<Edge>(
            (a, b) -> b.weight - a.weight
        );
        
        int[] distance = new int[V];
        Arrays.fill(distance, INFINITY);
        pq.offer(new Edge(src, 0));
        distance[src] = 0;
        
        Edge edge;
        int node, wt;
        while(!pq.isEmpty())
        {
            edge = pq.poll();
            wt = edge.weight;
            node = edge.dest;
            
            for(Edge e:adjMatrix.get(node))
            {
                int nextWt = e.weight, nextDest = e.dest;
                if((nextDest==dest && node==src) || (node==dest && nextDest==src))
                    continue;
                
                if(wt+nextWt < distance[nextDest])
                {
                    distance[nextDest] = wt+nextWt;
                    pq.offer(new Edge(nextDest, distance[nextDest]));
                }
            }
        }
        return distance[dest];
        
    }
    public int findMinCycle(int V, int[][] edges) {
        // code here
        ArrayList<ArrayList<Edge>> adjMatrix = new ArrayList<>(V);
        for(int i=0; i<V; i++)
            adjMatrix.add(new ArrayList<>());
            
        int u, v, w;
        for(int[] edge:edges)
        {
            u = edge[0];
            v = edge[1];
            w = edge[2];
            adjMatrix.get(u).add(new Edge(v,w));
            adjMatrix.get(v).add(new Edge(u,w));
        }
        
        int minCycleLength = Integer.MAX_VALUE;
        for(int[] edge: edges)
        {
            int distance = RunDijkstra(edge[0], edge[1], adjMatrix);
            if(distance != INFINITY)
            {
                minCycleLength = Math.min(minCycleLength, distance+edge[2]);
            }
        }
        return minCycleLength;
    }
};
