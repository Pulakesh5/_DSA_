class Solution {
    static class Cell{
        int r;
        int c;
        int t;
        Cell(int r, int c, int t) {
            this.r = r;
            this.c = c;
            this.t = t;
        }
    }
    static int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    public int orangesRotting(int[][] mat) {
        // Code here
        int ROW = mat.length;
        int COL = mat[0].length;
        
        Deque<Cell> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[ROW][COL];
        
        int freshOrange = 0;
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++) {
                if(mat[i][j]==1)
                    freshOrange++;
                else if(mat[i][j]==2)
                {
                    q.offer(new Cell(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }
        int finalTime = 0;
        while(!q.isEmpty()) {
            Cell cell = q.poll();
            int r = cell.r, c = cell.c, time = cell.t;
            finalTime = Math.max(finalTime, time);
            for(int i=0; i<4; i++) {
                int nr = r+dirs[i][0];
                int nc = c+dirs[i][1];
                
                if(nr>=0 && nc>=0 && nr<ROW && nc<COL && !visited[nr][nc] && mat[nr][nc]==1)
                {
                    q.offer(new Cell(nr, nc, time+1));
                    visited[nr][nc] = true;
                    freshOrange--;
                }
            }
        }
        
        return (freshOrange == 0) ? finalTime : -1;
    }
}
