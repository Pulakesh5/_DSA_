
class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    public void traverse(ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> traversal, int node, boolean[] visited) {
        visited[node] = true;
        traversal.add(node);
        for(Integer next:adj.get(node))
        {
            if(!visited[next])
                traverse(adj, traversal, next, visited);
        }
    }
    public ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> traversal = new ArrayList<Integer>();
        int N = adj.size();
        boolean[] visited = new boolean[N];
        for(int i=0; i<N; i++) {
            if(!visited[i])
                traverse(adj, traversal, 0, visited);
        }
        return traversal;
    }
}
