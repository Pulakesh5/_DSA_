class Solution {
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        int N_Nodes = V;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0; i<N_Nodes; i++)
            adj.add(new ArrayList<>());
            
        int N_edges = edges.length;
        for(int i=0; i<N_edges; i++) {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        } 
        
        int[] parent = new int[V];
        boolean[] visited = new boolean[N_Nodes];
        Queue<Integer> q = new ArrayDeque<Integer>();
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                q.offer(i);
                parent[i] = -1;
                visited[i] = true;
                while(q.size()>0) {
                    int node = q.poll();
                    for(Integer next:adj.get(node)) {
                        if(!visited[next]) {
                            parent[next] = node;
                            visited[next] = true;
                            q.offer(next);
                        } 
                        else if(parent[next] != node)
                            return true;
                    }
                }
            }
        }
        return false;
        
    }
}
