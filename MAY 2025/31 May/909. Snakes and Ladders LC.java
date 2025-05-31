class Solution {
    class Pair{
        int NoOfDiceRoll, cell;
        public Pair(int cell, int roll)
        {
            this.cell = cell;
            this.NoOfDiceRoll = roll;
        }
    }
    public int snakesAndLadders(int[][] board) {
        int N = board.length;
        int[] flatBoard = new int[N*N+5];
        Arrays.fill(flatBoard, N*N+1);

        for(int row=0; row<N; row++)
        {
            for(int col=0; col<N; col++)
            {
                int cell = row*N+col+1;
                
                if(row%2==0)
                    flatBoard[cell] = board[N-1-row][col];
                else
                    flatBoard[cell] = board[N-1-row][N-1-col];
                // System.out.println(row+" "+col+" : "+cell+" flatboard = "+flatBoard[cell]);
            }

        }
        
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(1,0));
        boolean[] visited = new boolean[N*N+5];
        visited[1] = true;

        while(!q.isEmpty())
        {
            Pair pr = q.poll();
            int distance = pr.NoOfDiceRoll, cell = pr.cell;

            if(cell==(N*N))
                return distance;
            
            for(int next=cell+1; next<=Math.min(N*N, cell+6); next++)
            {
                int dest = (flatBoard[next] == -1) ? next : flatBoard[next];
                if (!visited[dest]) {
                    visited[dest] = true;
                    q.offer(new Pair(dest, distance+1));
                }          
            }
        }

        return -1;
    }
}
