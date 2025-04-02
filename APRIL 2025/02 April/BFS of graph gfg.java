// User function Template for Java
class Solution {
    // Function to return Breadth First Search Traversal of given graph.
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        // code here
        ArrayList<Integer> traversal = new ArrayList<>();
        Queue<Integer> q = new ArrayDeque<>();
        boolean[] visited = new boolean[adj.size()];
        q.offer(0);
        visited[0] = true;
        while(!q.isEmpty()) {
            int node = q.poll();
            traversal.add(node);
            for(Integer next:adj.get(node)) {
                if(visited[next])
                    continue;
                q.offer(next);
                visited[next] = true;
            }
        }
        
        return traversal;
        
    }
}
