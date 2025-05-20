class Solution {
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
        // Code Here.
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        pq.offer(new int[]{0, 0}); // edge[0] = weight, edge[1] = destination
        
        boolean[] visited = new boolean[V];
        
        int[] edge;
        int MST_weight = 0, MST_size = 0;
        
        while(!pq.isEmpty())
        {
            edge = pq.poll();
            int node = edge[1], weight = edge[0];
            if(visited[node])
                continue;
            visited[node] = true;
            MST_weight += weight;
            MST_size++;
            for(int[] next:adj.get(node))
            {
                if(visited[next[0]])    
                    continue;
                pq.offer(new int[] {next[1], next[0]});
            }
            if(MST_size==V)
                return MST_weight;
        }
        return -1;
    }
}
