class Solution {
    public void floydWarshall(int[][] dist) {
        // Code here
        int INFINITY = (int)(1e8);
        int NODE = dist.length;
        for(int intermediate = 0; intermediate<NODE; intermediate++)
        {
            for(int src=0; src<NODE; src++)
            {
                for(int dest=0; dest<NODE; dest++)
                {
                    if(dist[src][intermediate]!=INFINITY && dist[intermediate][dest]!=INFINITY)
                    {
                        dist[src][dest] = Math.min(dist[src][intermediate] + dist[intermediate][dest], dist[src][dest]);
                    }
                }
            }
        }
    }
}
