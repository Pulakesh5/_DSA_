class Solution {
    class cell {
        int x, y;
        public  cell(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int dir[][] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

    public int countIslands(char[][] grid) {
        // Code here
        int ROW = grid.length, COL = grid[0].length;
        int countIsland = 0;
        
        for(int x=0; x<ROW; x++) {
            for(int y=0; y<COL; y++) {
                if(grid[x][y]=='L')
                {
                    // System.out.println("Executing BFS for "+x+" "+y);
                    Queue<cell> q = new ArrayDeque<>();
                    q.offer(new cell(x, y));
                    grid[x][y] = 'l';
                    
                    int nx, ny;
                    while(!q.isEmpty()) {
                        cell c = q.poll();
                        for(int k=0; k<8; k++) {
                            nx = c.x + dir[k][0];
                            ny = c.y + dir[k][1];
                            
                            if(nx>=0 && ny>=0 && nx<ROW && ny<COL && grid[nx][ny] == 'L')
                            {
                                grid[nx][ny] = 'l';
                                // System.out.println("Pushing "+nx+" "+ny);
                                q.offer(new cell(nx, ny));
                            }
                        }
                    }
                    countIsland++;
                }
                // System.out.print(grid[x][y]);
            }
        }
        return countIsland;
    }
}
