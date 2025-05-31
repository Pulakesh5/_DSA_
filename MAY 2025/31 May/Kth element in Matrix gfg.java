class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        // code here
        // 16 28 60 64
        // 22 41 63 91
        // 27 50 87 93
        // 36 78 87 94
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->Integer.compare(b,a));
        int N = matrix.length;
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(pq.size()<k)
                    pq.offer(matrix[i][j]);
                else if(pq.peek()>matrix[i][j])
                {
                    pq.poll();
                    pq.offer(matrix[i][j]);
                }
            }
        }
        return pq.poll();
    }
}
