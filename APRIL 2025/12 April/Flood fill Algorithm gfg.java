class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        // Code here
        int original = image[sr][sc];
        int ROW = image.length, COL = image[0].length;
        
        // int[][] visited = new int[ROW][COL];
        
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {sr, sc});
        image[sr][sc] = newColor;
        
        while(!q.isEmpty())
        {
            int[] node = q.poll();
            int row = node[0];
            int col = node[1];
            int[][] adjList = {
                {row-1, col}, {row, col+1},{row+1, col},{row, col-1}
            };
            for(int neighbour[]: adjList){
                int r = neighbour[0];
                int c = neighbour[1];
                if(r<0 || r>=ROW || c<0 || c>=COL || image[r][c]!=original || image[r][c] == newColor){
                    continue;
                }
                q.offer(new int[]{r,c});
                image[r][c] = newColor;
            }
        }
        
        return image;
    }
}
