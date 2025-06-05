class Solution {
    public int dfs(int node, int dest, ArrayList<ArrayList<Integer>> adjList, int[] incomingPath)
    {
        if(node==dest)
            return 1;
        if(incomingPath[node]!=-1)
            return incomingPath[node];
        
        int totalPath = 0;
        for(int next:adjList.get(node))
        {
            totalPath += dfs(next, dest, adjList, incomingPath);
        }
        return incomingPath[node] = totalPath;
    }
    
    public int countPaths(int[][] edges, int V, int src, int dest) {
        // Code here
        int[] incomingPath = new int[V];
        Arrays.fill(incomingPath, -1);
        
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        
        for(int i=0; i<V; i++)
            adjList.add(new ArrayList<>());
            
        for(int[] edge:edges)
        {
            adjList.get(edge[0]).add(edge[1]);
        }
        
        return dfs(src, dest, adjList, incomingPath);
    }
}
