class Solution {
    class cell{
        int x, y; 
        public cell(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int[][] dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    public int orangesRotting(int[][] grid) {
        Queue<cell> q = new ArrayDeque<>();
        int ROW = grid.length, COL = grid[0].length;
        int freshOrange = 0;
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++)
            {
                if(grid[i][j]==2)
                    q.offer(new cell(i,j));
                if(grid[i][j]==1)
                    freshOrange++;
            }
        }
        
        if(freshOrange==0)  
            return 0;

        int minute = -1;
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                cell c = q.poll();
                for(int k=0; k<4; k++)
                {
                    int nx = c.x+dir[k][0], ny = c.y+dir[k][1];
                    if(nx>=0 && ny>=0 && nx<ROW && ny<COL && grid[nx][ny]==1)
                    {
                        q.offer(new cell(nx,ny));
                        grid[nx][ny] = -1;
                        freshOrange--;
                    }
                }
            }
            minute++;
        }
        return (freshOrange==0) ? minute : -1;
    }
}
