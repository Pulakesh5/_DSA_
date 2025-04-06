class Solution {
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        int[] indegree = new int[V];
        
        List<List<Integer>> adj = new ArrayList<>(V);
        for(int i=0; i<V; i++)
            adj.add(new ArrayList<>());
            
        int EdgeNo = edges.length;
        for(int i=0; i<EdgeNo; i++)
        {
            adj.get(edges[i][0]).add(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        Queue<Integer> q = new ArrayDeque<>();
        for(int i=0; i<V; i++) // Initialize queue with the vertices who has no incoming edge
        {
            if(indegree[i] == 0)
                q.offer(i);
        }
        
        ArrayList<Integer> topoTraversal = new ArrayList<>();
        while(!q.isEmpty())
        {
            int node = q.poll();
            topoTraversal.add(node);
            for(Integer next:adj.get(node))    
            {
                indegree[next]--;
                if(indegree[next]==0)
                    q.offer(next);
            }
        }
        return topoTraversal;
    }
}
