class Solution {
    
    
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        int[] indegree = new int[V];
        List<List<Integer>> adj = new ArrayList<>(V);
        
        for(int i=0; i<V; i++)
            adj.add(new ArrayList<>());
            
        int NoOfEdges = edges.length;
        for(int i=0; i<NoOfEdges; i++)
        {
            if(edges[i][0] == edges[i][1])
                return true;
            indegree[edges[i][1]]++;
            adj.get(edges[i][0]).add(edges[i][1]);
        }
        
        Queue<Integer> q = new ArrayDeque<>();
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0)
            {
                q.offer(i);
                
            }
            
        }
        
        int encountered = 0;
        while(!q.isEmpty())
        {
            int node = q.poll();
            encountered++;
            for(int next:adj.get(node))
            {
                indegree[next]--;
                
                if(indegree[next] == 0)
                {
                    q.offer(next);

                }
            }
        }
        // System.out.println(encountered);
        return encountered<V;
        
        // 0 -> 1
        // |
        // v
        // 2
        
        // 4 <-> 3
        
    }
}
