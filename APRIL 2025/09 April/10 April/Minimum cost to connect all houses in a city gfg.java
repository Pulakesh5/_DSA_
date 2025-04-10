class Solution {
    class Edge implements Comparable<Edge> {
        int cost;
        int source;
        int destination;
        public Edge(int c, int s, int d)
        {
            this.cost = c;
            this.source = s;
            this.destination = d;
        }
        
        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.cost, other.cost);
        }
    }
    public int minCost(int[][] houses) {
        // code here
        int N = houses.length;
        boolean[] visited = new boolean[N];
        
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        
        for(int i=1; i<N; i++) 
        {
            int distance = Math.abs(houses[0][0]-houses[i][0]) + Math.abs(houses[0][1]-houses[i][1]);
            pq.offer(new Edge(distance, 0, i));
        }
        visited[0] = true;

        int minTotalCost = 0;
        
        while(!pq.isEmpty())
        {
            Edge e = pq.poll();
            int d = e.destination;
            if(visited[d])
                continue;
            
            visited[d] = true;
            
            minTotalCost += e.cost;
            
            for(int i=0; i<N; i++)
            {
                if(!visited[i])
                {
                    int distance = Math.abs(houses[d][0]-houses[i][0]) + Math.abs(houses[d][1]-houses[i][1]);
                    pq.offer(new Edge(distance, d, i));
                }
            }
        }
        return minTotalCost;
        
    }
}
