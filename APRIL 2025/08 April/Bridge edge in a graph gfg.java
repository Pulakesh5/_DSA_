class Solution {
    public boolean isBridge(int V, int[][] edges, int c, int d) {
        // code here
        List<List<Integer>> adj = new ArrayList<>(V);
        
        for(int i=0; i<V; i++)
            adj.add(new ArrayList<Integer>());
        
        // keeping this visited array to do keep track of what its name suggest  
        boolean[] visited = new boolean[V];
        int NoOfEdges = edges.length;
        
        for(int i=0; i<NoOfEdges; i++)
        {
            if((edges[i][0]==c&&edges[i][1]==d) || (edges[i][0]==d&&edges[i][1]==c))
                continue;
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
            
        }
        
        // for(int i=0; i<V; i++)
        // {
        //     System.out.print(i+" : ");
        //     for(int next:adj.get(i))
        //         System.out.print(next+" -> ");
        //     System.out.println();
        // }
        
        for(int i=0; i<V; i++)
        {
            if(visited[i])
                continue;
            // Initializing for BFS
            Queue<Integer> q = new ArrayDeque<>();
            q.offer(i);
            visited[i] = true;
            
            while(!q.isEmpty())
            {
                int node = q.poll();
                // System.out.print(node+" -> ");
                for(int next:adj.get(node))
                {
                    if(visited[next])
                        continue;
                    q.offer(next);
                    visited[next] = true;
                }
            }
            // System.out.println();
            if(visited[c]!=visited[d])
                return true;
        }
        
        return false;
    }
}
