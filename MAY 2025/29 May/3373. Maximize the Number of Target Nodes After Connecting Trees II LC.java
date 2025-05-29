class Solution {
    public int dfs(int node, int parent, ArrayList<ArrayList<Integer>> adjList, int[] parity, int isEven)
    {
        int target = isEven;
        parity[node] = isEven;
        for(int next:adjList.get(node))
        {
            if(next!=parent)
                target += dfs(next, node, adjList, parity, 1-isEven);
        }
        return target;
    }
    public ArrayList<ArrayList<Integer>> getAdjList(int[][] edges)
    {
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        int N = edges.length+1;
        for(int i=0; i<N; i++) adjList.add(new ArrayList<>());
        for(int[] edge:edges)
        {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        return adjList;
    }
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        // lets color the nodes of Graph1 as 0 or 1, so all 0(or 1) nodes will at even distance with other 0(or 1).
        int m = edges1.length+1, n = edges2.length+1;
        int[] parity1 = new int[m];
        int[] parity2 = new int[n];
        
        int evenCount1 = dfs(0, -1, getAdjList(edges1), parity1, 1), oddCount1 = m-evenCount1;
        int evenCount2 = dfs(0, -1, getAdjList(edges2), parity2, 1), oddCount2 = n-evenCount2;
    
        int[] ans = new int[m];
        for(int i=0; i<m; i++)
        {
            ans[i] = (parity1[i] == 1? evenCount1: oddCount1) + Math.max(evenCount2, oddCount2); // because we have choice to connect to a 0 or 1 node 
        }
        
        return ans;
    }
}
