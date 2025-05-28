class Solution {
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
    public int[] count_nodes(ArrayList<ArrayList<Integer>> adjList, int k)
    {
        int N = adjList.size();
        int[] count = new int[N];
        if(k<0)
            return count;
        for(int i=0; i<N; i++)
        {
            count[i] = 1;
            
            // running BFS on each vertice and keeping the count of nodes reachable by atmost k distance
            Queue<int[]> q = new LinkedList<>();
            q.offer(new int[]{i,-1});

            int distance = k;
            while(distance>0)
            {
                int qsize = q.size();

                for(int j=0; j<qsize; j++)
                {
                    int[] it = q.poll();
                    int node = it[0], parent = it[1];

                    for(int next:adjList.get(node))
                    {
                        if(next==parent) continue;

                        count[i]++;
                        q.offer(new int[]{next, node});
                    }
                }
                distance--;
            }

        }
        return count;
    }
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2, int k) {
        ArrayList<ArrayList<Integer>> adjList1 = getAdjList(edges1);
        ArrayList<ArrayList<Integer>> adjList2 = getAdjList(edges2);
        
        
        int[] count1 = count_nodes(adjList1, k);
        
        int[] count2 = count_nodes(adjList2, k-1);
            
        int max2 = Arrays.stream(count2).max().getAsInt();
        int N1 = count1.length;
        for(int i=0; i<N1; i++)
            count1[i] += max2;
        
        return count1;
    }
}
