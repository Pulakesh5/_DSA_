class Solution {
    // Conditions to be a articulation point:
    // 1. Root with more than 1 child
    // 2. Back edge exists between current node and a higher node
    static int time = 0;
    static void dfs(ArrayList<ArrayList<Integer>> adj, boolean[] visited,
            int[] timeOfInsertion, int[] lowestTime, int node, int parent, int[] articulationPoint) 
    {
        visited[node] = true;
        timeOfInsertion[node] = ++time;
        lowestTime[node] = time;
        int childCount = 0;
        
        for(int child:adj.get(node))
        {
            if(!visited[child]) // if not visited, run dfs
            {
                dfs(adj, visited, timeOfInsertion, lowestTime, child, node, articulationPoint);
                childCount++;
                // update lowest time to reach 'node'
                lowestTime[node] = Math.min(lowestTime[child], lowestTime[node]);
                
                // this comparison ensures that child is only reachable after visiting current node
                if(parent!=-1 && lowestTime[child]>=timeOfInsertion[node]) 
                    articulationPoint[node] = 1;
            }
            else if(child!=parent)
                lowestTime[node] = Math.min(lowestTime[node], timeOfInsertion[child]);
            // otherwise the child is actually its parent [DARK vibes], then skip
        }
        
        if(parent==-1 && childCount>1)
            articulationPoint[node] = 1;
    }
    
    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {
        // code here
        
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0; i<V; i++)
            adj.add(new ArrayList<>());
        
        int NoOfEdges = edges.length;
        // building adjacency list by traversing edges array
        for(int i=0; i<NoOfEdges; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        boolean[] visited = new boolean[V];
        int[] timeOfInsertion = new int[V], lowestTime = new int[V];
        int[] IsArticulationPoint = new int[V];
        // initializing dfs call through all unvisited nodes
        for(int node=0; node<V; node++)
        {
            if(visited[node])
                continue;
            int parent = -1;
            dfs(adj, visited, timeOfInsertion, lowestTime, node, parent, IsArticulationPoint);
        }
        
        ArrayList<Integer> articulationPoint = new ArrayList<>();
        
        for(int i=0; i<V; i++)
        {
            if(IsArticulationPoint[i]==1)
                articulationPoint.add(i);
        }
        
        if(articulationPoint.size()==0)
        {
            ArrayList<Integer> list = new ArrayList<Integer>();
            list.add(-1);
            return list;
        }
        
        return articulationPoint;
        
    }
}
