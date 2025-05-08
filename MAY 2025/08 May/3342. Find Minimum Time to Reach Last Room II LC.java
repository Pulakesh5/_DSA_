class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int R = moveTime.length, C = moveTime[0].length;
        int[][] dp = new int[R][C];
        for(int[] row:dp)
            Arrays.fill(row, Integer.MAX_VALUE);
        
        PriorityQueue<int[]> minPQ = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        minPQ.add(new int[]{0,0,0});
        moveTime[0][0] = 0;

        int[][] directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!minPQ.isEmpty())
        {
            int[] cell = minPQ.poll();
            int time = cell[0];
            int row = cell[1];
            int col = cell[2];

            if(time >= dp[row][col])
                continue;
            
            if(row==R-1 && col==C-1)
                return time;
            
            dp[row][col] = time;
            for(int[] direction:directions)
            {
                int nextRow = row+direction[0];
                int nextCol = col+direction[1];
                if(nextRow>=0 && nextRow<R && nextCol>=0 && nextCol<C && dp[nextRow][nextCol]==Integer.MAX_VALUE)
                {
                    int nextTime = Math.max(moveTime[nextRow][nextCol], time)+1;
                    minPQ.add(new int[]{nextTime, nextRow, nextCol});
                }
            }
        }

        return -1;
    }
}
