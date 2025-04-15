class Solution {
    public int[] bellmanFord(int V, int[][] edges, int src) {
        // code here
        int INFINITY = (int)1e8;
        int[] distance = new int[V];
        Arrays.fill(distance, INFINITY);
        int u, v, w;        
        distance[src] = 0;
        for(int i=0; i<V; i++)
        {
            for(int[] edge:edges)    
            {
                u = edge[0];
                v = edge[1];
                w = edge[2];
                
                if(distance[u]!=INFINITY && distance[u]+w<distance[v])  
                    distance[v] = distance[u]+w;
            }
        }
        
        for(int[] edge:edges)
        {
            u = edge[0];
            v = edge[1];
            w = edge[2];
            if(distance[u]!=INFINITY && distance[u]+w<distance[v])
                return new int[]{-1};
        }
        return distance;
    }
}
