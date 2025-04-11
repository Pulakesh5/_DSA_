class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        // code here
        List<List<int[]>> adj = new ArrayList<>();
        // initialize the empty adjacency matrix with destination, weight
        for(int i=0; i<V; i++)
            adj.add(new ArrayList<>());
        
        int u, v, w;
        for(int[] edge:edges)
        {
            u = edge[0];
            v = edge[1];
            w = edge[2];
            
            adj.get(u).add(new int[] {v, w});
            adj.get(v).add(new int[] {u, w});
        }
        
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[src] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[0]-b[0]); // distance, node
        pq.add(new int[] {0, src});
        
        // int node, dist_node, next, dist_next;
        while(!pq.isEmpty()) 
        {
            int[] it = pq.poll();
            int node = it[1]; 
            int dist_node = it[0];
            
            for(int[] edge:adj.get(node))
            {
                int next = edge[0];
                int dist_next = edge[1];
                
                if(dist_node+dist_next < distance[next])
                {
                    distance[next] = dist_node+dist_next;
                    pq.add(new int[]{distance[next], next});
                }
            }
        }
        
        return distance;
    }
}
